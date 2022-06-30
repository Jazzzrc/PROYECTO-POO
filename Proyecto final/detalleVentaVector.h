#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include"detalleVenta.h"
using namespace std;
class DetalleVentaVector
{
  private:
    vector<DetalleVenta> vectorDetalleVenta;
  public:
    DetalleVentaVector()
    {
      cargarDatos();
    }

    DetalleVenta buscarEliminar(int codigo)
    {
        DetalleVenta objError;
        objError.setCodVenta(getCorrelativo());
        for(DetalleVenta x:vectorDetalleVenta)
        {
          if(codigo == x.getCodVenta())
          {
            return x;
          }
        }
        return objError;
    }

    int getCorrelativo()
		{
			if(vectorDetalleVenta.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorDetalleVenta[vectorDetalleVenta.size() - 1].getCodVenta() + 1;
			}
		}

    void add(DetalleVenta obj)
    {
      vectorDetalleVenta.push_back(obj);
    }

    DetalleVenta get(int pos)
    {
      return vectorDetalleVenta[pos];
    }

    int rows()
    {
      return vectorDetalleVenta.size();
    }

    void remove(DetalleVenta obj)
    {
      vectorDetalleVenta.erase(vectorDetalleVenta.begin() + getPostArray(obj));
    }

    int getPostArray(DetalleVenta obj)
    {
      for(int i=0;i<vectorDetalleVenta.size();i++)
      {
        if(obj.getCodVenta() == vectorDetalleVenta[i].getCodVenta())
        {
          return i;
        }
        return -1;
      }
    }

    double getTotalVenta()
    {
      float st=0;
      for(int i=0; i<vectorDetalleVenta.size(); i++)
      {
        st+=vectorDetalleVenta[i].getPreVenta();
      }
      return st;
    }

    void grabar(DetalleVenta obj)
    {
      try
      {
        fstream archivoDetalleVenta;
        archivoDetalleVenta.open("detalleVenta.csv",ios::app);
        if(archivoDetalleVenta.good())
        {
          archivoDetalleVenta<<obj.getCodVenta()<<";"<<obj.getCodProducto()<<";"<<obj.getCantidad()<<";"<<obj.getPreVenta()<<endl;
          archivoDetalleVenta.close();
        }
        else
        {
          cout<<"ARCHIVO DAÑADO!!";
        }
      }
      catch(exception e)
      {
        cout<<"OCURRIO UN ERROR AL GRABAR";
      }
    }

    void grabarModificar()
    {
      try
      {
        fstream archivoDetalleVentas;
        archivoDetalleVentas.open("detalleVenta.csv", ios::out);
        if(archivoDetalleVentas.is_open())
        {
          for(DetalleVenta x : vectorDetalleVenta)
          {
            archivoDetalleVentas << x.getCodVenta() << ";" << x.getCodProducto() << ";" << x.getCantidad() << ";" << x.getPreVenta() << "\n";
          }
          archivoDetalleVentas.close();
        }
      }
      catch(exception e)
      {
        cout<<"OCURRIO UN ERROR AL MODIFICAR";
      }
    }

    void cargarDatos()
    {
      try
      {
        int i;
        size_t posi;
        string linea;
        string temporal[4];

        fstream archivoDetalleVenta;
        archivoDetalleVenta.open("detalleVenta.csv",ios::in);
        if(archivoDetalleVenta.is_open())
        {
          while(!archivoDetalleVenta.eof() && (getline(archivoDetalleVenta,linea)))
          {
            i=0;
            while((posi = linea.find(";")) != string::npos)
            {
              temporal[i]=linea.substr(0,posi);
              linea.erase(0,posi + 1);
              ++i;
            }
            DetalleVenta obj;
            obj.setCodVenta(std::stoi(temporal[0]));
            obj.setCodProducto(std::stoi(temporal[1]));
            obj.setCantidad(std::stoi(temporal[2]));
            obj.setPreVenta(std::stoi(temporal[3]));

            add (obj);
          }
        }
        archivoDetalleVenta.close();
      }
      catch(exception e)
      {
        cout<<"ERROR AL CARGAR ARHIVO"<<endl;
      }
    }
};
