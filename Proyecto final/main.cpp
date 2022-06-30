#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include"empleadoVector.h"
#include"ventaVector.h"
#include"productoVector.h"
#include"detalleVentaVector.h"
using namespace std;
using std::vector;

EmpleadoVector empleadoVector;
DetalleVentaVector detalleVentaVector;
VentaVector ventaVector;
Producto pro100,
         pro101,
         pro102,
         pro103,
         pro104,
         pro105,
         pro106,
         pro107;
string bandera,
       usu;
int cod;

void menuOpciones();
void agregarEmpleado();
void iniciarSesion();
void listar();
void carrito();
void boleta();
int main()
  {
      menuOpciones();
  }
void menuOpciones()
{
  int opcion;
  do
  {
    cout<<"\t########### SERVICIOS ###########\n";
    cout<<"\t###    AGREGAR EMPLEADO(1)    ###\n";
    cout<<"\t###    INICIAR SESION(2)      ###\n";
    cout<<"\t###    LISTAR EMPLEADOS(3)    ###\n";
    cout<<"\t###    CERRAR PROGRAMA(4)     ###\n";
    cout<<"\t#################################"<<endl;
    cout<<"\tINGRESAR OPCION: ";
    cin>>opcion;
    switch(opcion)
    {
      case 1:system("cls");agregarEmpleado();break;
      case 2:system("cls");iniciarSesion();break;
      case 3:system("cls");listar();break;
      case 4:system("cls");cout<<"\n\t***** GRACIAS POR USAR NUESTRO PROGRAMA *****"<<endl;break;
      defaul:cout<<"INGRESE UNA OPCION VALIDA!!!";
    }
  }while(opcion!=4);
}

void agregarEmpleado()
  {
    do
    {
      cod = empleadoVector.getCorrelativo();
      cout<<"\t***** CODIGO("<<cod<<") *****\n";
      cin.ignore();
      cout << "INGRESAR EL NOMBRE: "<<endl;
      getline(cin,usu);

      Empleado empleado;
      empleado.setUsuario(usu);
      empleado.setCod(cod);
      empleadoVector.add(empleado);
      empleadoVector.grabarArchivo(empleado);
      cout<<"AGREGAR OTRO EMPLEADO(S/N):";
      cin>>bandera;

      system("cls");

    } while(bandera == "si" || bandera == "s" || bandera == "SI" || bandera == "S");
  }

void iniciarSesion()
  {
    string usuario,
           seguro,
           seguro2,
           metodo,
           estado,
           nombre;
    int cantidad,
        item0 = 0,
        item1 = 0,
        item2 = 0,
        item3 = 0,
        item4 = 0,
        item5 = 0,
        item6 = 0,
        item7 = 0,
        codigo,
        codcli,
        codVen,
        tarjeta,
        numeroVen,
        opt;
    float monto,
          importeTotal;

    cout<<"USUARIO: "<<endl;
    cin>>usuario;
    Empleado usuarioBuscar = empleadoVector.ingresarConNombre(usuario);
    system("cls");

    if (usuarioBuscar.getUsuario() != "Error")
    {
      do
      {
        do
        {
          cout<<"\t|                      TIENDA ventaMAS                        |"<<endl;
          cout<<"\t|*************************************************************|"<<endl;
          cout<<"\t|  Cereal ChocoKrispy ..(100) | Queso Cheddar .........(104)  |"<<endl;
          cout<<"\t|  Yogurt Laive ........(101) | Cafe Altomayo Grande ..(105)  |"<<endl;
          cout<<"\t|  Leche Gloria ........(102) | Vino Queirolo .........(106)  |"<<endl;
          cout<<"\t|  Tostada Bimbo .......(103) | Cerveza Pilsen ........(107)  |"<<endl;
          cout<<"\t|*************************************************************|"<<endl;
          codVen = detalleVentaVector.getCorrelativo();
          cout<<"Ingresar codigo: ";
          cin>>codigo;
          cin.ignore();
          cout<<"Cantidad: ";
          cin>>cantidad;

          DetalleVenta detalleVenta;
          detalleVenta.setCodVenta(codVen);
          detalleVenta.setCantidad(cantidad);
          detalleVenta.setCodProducto(codigo);
          if (codigo == 100)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*15.5);
          }

          else if(codigo == 101)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*5.0);
          }

          else if(codigo == 102)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*3.60);
          }

          else if(codigo == 103)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*8.99);
          }

          else if(codigo == 104)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*8.90);
          }

          else if(codigo == 105)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*29.7);
          }

          else if(codigo == 106)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*17.9);
          }

          else if(codigo == 107)
          {
            detalleVenta.setPreVenta(detalleVenta.getCantidad()*6.5);
          }
          detalleVentaVector.add(detalleVenta);
          detalleVentaVector.grabar(detalleVenta);

          Producto pro100;
          pro100.setCodigo(100);
          pro100.setNombre("Cereal ChocoKrispy");
          pro100.setPrecio(15.5);
          pro100.setStock(100);

          Producto pro101;
          pro101.setCodigo(101);
          pro101.setNombre("Yogurt Laive");
          pro101.setPrecio(5.0);
          pro101.setStock(230);

          Producto pro102;
          pro102.setCodigo(102);
          pro102.setNombre("Leche Gloria");
          pro102.setPrecio(3.60);
          pro102.setStock(250);

          Producto pro103;
          pro103.setCodigo(103);
          pro103.setNombre("Tostada Bimbo");
          pro103.setPrecio(8.99);
          pro103.setStock(300);

          Producto pro104;
          pro104.setCodigo(104);
          pro104.setNombre("Queso Cheddar");
          pro104.setPrecio(8.90);
          pro104.setStock(200);

          Producto pro105;
          pro105.setCodigo(105);
          pro105.setNombre("Cafe Altomayo Grande");
          pro105.setPrecio(29.7);
          pro105.setStock(100);

          Producto pro106;
          pro106.setCodigo(106);
          pro106.setNombre("Vino Queirolo");
          pro106.setPrecio(17.9);
          pro106.setStock(50);

          Producto pro107;
          pro107.setCodigo(107);
          pro107.setNombre("Cerveza Pilsen");
          pro107.setPrecio(6.5);
          pro107.setStock(200);

          if(codigo == 100)
          {
            cout<<"CODIGO: "   <<pro100.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro100.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro100.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro100.getStock() - cantidad<<endl;
          }

          else if(codigo == 101)
          {
            cout<<"CODIGO: "   <<pro101.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro101.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro101.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro101.getStock() - cantidad<<endl;
          }

          else if(codigo == 102)
          {
            cout<<"CODIGO: "   <<pro102.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro102.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro102.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro102.getStock() - cantidad<<endl;
          }

          else if(codigo == 103)
          {
            cout<<"CODIGO: "   <<pro103.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro103.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro103.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro103.getStock() - cantidad<<endl;
          }

          else if(codigo == 104)
          {
            cout<<"CODIGO: "   <<pro104.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro104.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro104.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro104.getStock() - cantidad<<endl;
          }

          else if(codigo == 105)
          {
            cout<<"CODIGO: "   <<pro105.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro105.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro105.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro105.getStock() - cantidad<<endl;
          }

          else if(codigo == 106)
          {
            cout<<"CODIGO: "   <<pro106.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro106.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro106.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro106.getStock() - cantidad<<endl;
          }

          else if(codigo == 107)
          {
            cout<<"CODIGO: "   <<pro107.getCodigo()<<endl;
            cout<<"NOMBRE: "   <<pro107.getNombre()<<endl;
            cout<<"PRECIO: S/."<<pro107.getPrecio()<<endl;
            cout<<"STOCK: "    <<pro107.getStock() - cantidad<<endl;
          }

          cout<<"Seguir comprando(S/N): ";
          cin>>seguro;
          system("cls");
        }while(seguro=="S" || seguro == "s" || seguro == "Si" || seguro == "SI");

        cout<<"##### PAGAR(S/N) #####"<<endl;
        cin>>seguro2;
        system("cls");
      }while(seguro2=="N" || seguro2== "n" || seguro2 == "No" || seguro2 == "NO");

      cout<<"\t####### METODO DE PAGO #######"<<endl;
      cout<<"\tEFECTIVO (E)   |   TARJETA (T)"<<endl;
      cout<<"\t##############################"<<endl;
      cin>>metodo;
      system("cls");

      if (metodo == "E" || metodo == "e")
      {
        cout<<"                       ##### CARRITO #####                  \n"<<endl;
        carrito();
        cout<<"                                         IMPORTE TOTAL: S/."<<detalleVentaVector.getTotalVenta()<<endl;
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"Ingresar monto: S/.";
        cin>>monto;
        cout<<"Cambio: S/."<<monto - detalleVentaVector.getTotalVenta()<<endl;
        cout<<"******************\n";
        cout<<"\tGRACIAS POR USAR NUESTRO SERVICIO"<<endl;
        system("pause");
        system("cls");
      }

      else if (metodo == "T" || metodo == "t")
      {
        cout<<"                       ##### CARRITO #####                  \n"<<endl;
        carrito();
        cout<<"                                         IMPORTE TOTAL: S/."<<detalleVentaVector.getTotalVenta()<<endl;
        cout<<"Numero de Tarjeta: ";
        cin>>tarjeta;
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"PROCESANDO PAGO...."<<endl;
        cout<<"PAGO REALIZADO SATISFACTORIAMENTE"<<endl;
        cout<<"\tGRACIAS POR USAR NUESTRO SERVICIO"<<endl;
        system("pause");
        system("cls");
      }

      cout<<"ESTADO: "<<endl;
      cin>>estado;

      numeroVen = ventaVector.getCorrelativo();
      codcli = ventaVector.getCorrelativoCli();
      Venta venta;
      venta.setFecha(300622);
      venta.setNumero(numeroVen);
      venta.setTotal(detalleVentaVector.getTotalVenta());
      venta.setCodigoCli(codcli);
      venta.setCodigoEmp(detalleVentaVector.getCorrelativo());
      venta.setEstado(estado);

      ventaVector.add(venta);
      ventaVector.grabarArchivo(venta);
      boleta();
      system("pause");
      system("cls");
    }

    else {
      cout<<"USUARIO INCORRECTO!!"<<endl;
    }
  }

void carrito()
{
  cout<<"CODIGO VENTA ..... CODIGO PRODUCTO ..... CANTIDAD ..... PRECIO"<<endl;
  for(int i=0; i<detalleVentaVector.rows();i++)
  {
    cout<<"   720"<<detalleVentaVector.get(i).getCodVenta()<<"      .....      "<<detalleVentaVector.get(i).getCodProducto()<<"        .....     "
    <<detalleVentaVector.get(i).getCantidad()<<"     ..... S/."<<detalleVentaVector.get(i).getPreVenta()<<endl;
  }
}

void boleta()
{
  cout<<" FECHA ..... NUMERO ....... TOTAL .... CODIGO CLIENTE ..... CODIGO EMPLEADO ..... ESTADO"<<endl;
  for(int i=0; i<ventaVector.rows();i++)
  {
    cout<<ventaVector.get(i).getFecha()<<" ..... 9754"<<ventaVector.get(i).getNumero()<<" ...... S/."<<ventaVector.get(i).getTotal()<<" ....     1246"
    <<ventaVector.get(i).getCodigoCli()<<"      .....        "<<ventaVector.get(i).getCodigoEmp()<<"           ..... "<<ventaVector.get(i).getEstado()<<endl;
  }
}

void listar()
{
  for(int i=0; i<empleadoVector.rows();i++)
  {
    cout<<empleadoVector.get(i).getUsuario()<<" ----- "<<empleadoVector.get(i).getCod()<<"\n";
  }
  system("pause");
  system("cls");
}
