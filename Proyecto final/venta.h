#include <iostream>
#include <string>
using namespace std;
class Venta
{
  private:
    int fecha,
        numeroVen,
        codigocliente,
        codigoEmpleado;
    float totalventa;
    string estado;
  public:
    Venta()
    {
    }
    ~Venta()
    {
    }

    //setters
    void setFecha(int fecha)
    {
      this->fecha = fecha;
    }

    void setNumero(float numero)
    {
      numeroVen = numero;
    }

    void setTotal(float total)
    {
      totalventa = total;
    }

    void setCodigoCli(int codigo)
    {
      codigocliente = codigo;
    }

    void setCodigoEmp(int codigoem)
    {
      codigoEmpleado = codigoem;
    }

    void setEstado(string estado)
    {
      this->estado = estado;
    }

    //getters
    int getFecha()
    {
      return fecha;
    }

    int getNumero()
    {
      return numeroVen;
    }

    float getTotal()
    {
      return totalventa;
    }

    int getCodigoCli()
    {
      return codigocliente;
    }

    int getCodigoEmp()
    {
      return codigoEmpleado;
    }

    string getEstado()
    {
      return estado;
    }

};
