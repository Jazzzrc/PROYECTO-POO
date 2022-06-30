#include <string>
using namespace std;
class DetalleVenta
{
  private:
    int codVenta,
        codProducto,
        cantidad;
   float preVenta;
  public:
    DetalleVenta()
    {
    }
    ~DetalleVenta()
    {
    }

    void setCodVenta(int codVenta)
    {
      this->codVenta = codVenta;
    }

    void setCodProducto(int codProducto)
    {
      this->codProducto = codProducto;
    }

    void setCantidad(int cantidad)
    {
      this->cantidad = cantidad;
    }

    void setPreVenta(int preVenta)
    {
      this->preVenta = preVenta;
    }

    int getCodVenta()
    {
      return codVenta;
    }

    int getCodProducto()
    {
      return codProducto;
    }

    int getCantidad()
    {
      return cantidad;
    }

    virtual float getPreVenta() const
    {
      return preVenta;
    }

};
