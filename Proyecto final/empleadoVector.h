#include<vector>
#include<iostream>
#include<fstream>
#include"empleado.h"
using namespace std;
class EmpleadoVector
{
  private:
    vector<Empleado> vectorEmpleado;
  public:
    EmpleadoVector()
    {
      cargarDatos();
    }

    int getCorrelativo()
    {
      if(vectorEmpleado.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorEmpleado[vectorEmpleado.size() - 1].getCod() + 1;
			}
    }

    void add (Empleado obj)
    {
      vectorEmpleado.push_back(obj);
    }

    Empleado ingresarConNombre(string usu)
    {
      Empleado objError;
      objError.setUsuario("Error");
      for(Empleado x:vectorEmpleado)
      {
        if(usu == x.getUsuario())
        {
          return x;
        }
      }
      return objError;
    }

    int rows()
    {
      return vectorEmpleado.size();
    }

    Empleado get(int pos)
    {
      return vectorEmpleado[pos];
    }

    void grabarArchivo(Empleado obj)
    {
      try
      {
        fstream archivoEmpleado;
        archivoEmpleado.open("empleados.csv",ios::app);
        if(archivoEmpleado.good())
        {
          archivoEmpleado<<obj.getUsuario()<<";"<<endl;
          archivoEmpleado.close();
        }
        else
        {
          cout<<"ARCHIVO DAÑADO!!";
        }

      }
      catch(exception e)
      {
        cout<<"OCURRIO UN ERROR AL GUARDAR EL ARCHIVO";
      }
    }

    void cargarDatos()
    {
        try
        {
          int i;
          size_t posi;
          string linea;
          string temporal[2];
          fstream archivoEmpleado;
          archivoEmpleado.open("alumno.csv",ios::in);
          if (archivoEmpleado.is_open())
          {
            while(!archivoEmpleado.eof() && (getline(archivoEmpleado,linea)))
            {
              i=0;
              while((posi = linea.find(";")) != string::npos)
              {
                temporal[i]=linea.substr(0,posi);
                linea.erase(0,posi + 1);
                ++i;
              }
              Empleado obj;
              obj.setUsuario(temporal[0]);
              obj.setCod(std::stoi(temporal[1]));

              add (obj);
            }
          } archivoEmpleado.close();
        }catch(exception e)
        {
          cout<<"OCURRIO UN ERROR AL CARGAR EL ARCHIVO";
        }
    }
};
