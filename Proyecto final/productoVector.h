#include<vector>
#include<iostream>
#include<fstream>
#include"producto.h"
using namespace std;
class ProductoVector
{
  private:
    vector<Producto> vectorProducto;
  public:
    ProductoVector()
    {
      cargarDatos();
    }

    void add (Producto obj)
    {
      vectorProducto.push_back(obj);
    }

    int rows()
    {
      return vectorProducto.size();
    }

    Producto get(int pos)
    {
      return vectorProducto[pos];
    }

    void grabarArchivo(Producto obj)
    {
      try
      {
        fstream archivoProducto;
        archivoProducto.open("producto.csv",ios::app);
        if (archivoProducto.good())
        {
          archivoProducto<<obj.getCodigo()<<";"<<obj.getNombre()<<";"<<obj.getPrecio()<<";"<<obj.getStock()<<endl;
          archivoProducto.close();
        }

        else
        {
          cout<<"NO TIENE PRODUCTO"<<endl;
        }
      }
      catch (exception e)
      {
        cout<<"NO TIENE PRODUCTOS"<<endl;
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
          fstream archivoProducto;
          archivoProducto.open("producto.csv",ios::in);
          if (archivoProducto.is_open())
          {
            while(!archivoProducto.eof() && (getline(archivoProducto,linea)))
            {
              i=0;
              while((posi = linea.find(";")) != string::npos)
              {
                temporal[i]=linea.substr(0,posi);
                linea.erase(0,posi + 1);
                ++i;
              }
              Producto obj;
              obj.setCodigo(std::stoi(temporal[0]));
              obj.setNombre(temporal[1]);
              obj.setPrecio(std::stoi(temporal[2]));
              obj.setStock(std::stoi(temporal[3]));

              add (obj);
            }
          } archivoProducto.close();
        }catch(exception e)
        {
          cout<<"OCURRIO UN ERROR AL CARGAR EL ARCHIVO";
        }
    }
};
