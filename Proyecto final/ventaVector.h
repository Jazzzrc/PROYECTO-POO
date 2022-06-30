#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include"venta.h"
using namespace std;
class VentaVector
{
	private:
		vector<Venta> vectorVenta;
	public:
		VentaVector()
		{
			cargarDatos();
		}

		int getCorrelativo()
		{
			if(vectorVenta.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorVenta[vectorVenta.size() - 1].getNumero() + 1;
			}
		}

		int getCorrelativoCli()
		{
			if(vectorVenta.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorVenta[vectorVenta.size() - 1].getCodigoCli() + 1;
			}
		}

		void add(Venta obj)
		{
		  vectorVenta.push_back(obj);
		}

		Venta get(int pos)
		{
			return vectorVenta[pos];
		}

		int rows()
		{
			return vectorVenta.size();
		}

		void grabarArchivo(Venta obj)
		{
			try
			{
				fstream archivoVenta;
				archivoVenta.open("venta.csv", ios::app);
				if(archivoVenta.good())
				{
					archivoVenta<<obj.getFecha()<<";"<<obj.getNumero()<<";"<<obj.getTotal()<<";"<<obj.getCodigoCli()<<";"<<obj.getCodigoEmp()<<";"<<obj.getEstado()<<endl;
					archivoVenta.close();
				}
				else
				{
					cout << "ARCHIVO DAÑADO!!!";
				}
			}catch(exception e)
			{
				cout << "Ocurrio un error al grabar en el archivo";
			}
		}

		void grabarModificar()
		{
			try
			{
				fstream archivoVentas;
				archivoVentas.open("venta.csv",ios::out);
				if(archivoVentas.is_open())
				{
					for(Venta x : vectorVenta)
					{
						archivoVentas<<x.getFecha()<<";"<<x.getNumero()<<";"<<x.getTotal()<<";"<<x.getCodigoCli()<<";"<<x.getCodigoEmp()<<";"<<x.getEstado()<<endl;
					}
					archivoVentas.close();
				}
			}
			catch ( exception e)
			{
				cout<<"OCURRIO UN ERROR AL MODIFICAR EL ARCHIVO"<<endl;
			}
		}

		void cargarDatos()
		{
			try
			{
				int i;
				size_t posi;
				string linea;
				string temporal[6];

				fstream archivoVenta;
				archivoVenta.open("venta.csv",ios::in);
				if(archivoVenta.is_open())
				{
						while(!archivoVenta.eof() && (getline(archivoVenta,linea)))
						{
								i=0;
								while((posi = linea.find(";")) != string::npos)
								{
									temporal[i]=linea.substr(0,posi);
		              linea.erase(0,posi + 1);
		              ++i;
								}
								Venta obj;
								obj.setFecha(std::stoi(temporal[0]));
								obj.setNumero(std::stoi(temporal[1]));
								obj.setTotal(std::stoi(temporal[2]));
								obj.setCodigoCli(std::stoi(temporal[3]));
								obj.setCodigoEmp(std::stoi(temporal[4]));
								obj.setEstado(temporal[5]);

								add (obj);
						}
				}
				archivoVenta.close();
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al momento de leer en el archivo!!!";
			}
		}
};
