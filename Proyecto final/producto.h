#include <string>
using namespace std;
class Producto
{
  private:
    int codigo;
    string nombre;
    float precio;
    int stock;
  public:
    Producto()
    {
    }
    ~Producto()
    {
    }

    void setCodigo(int cod)
    {
      codigo = cod;
    }

    void setNombre(string nom)
    {
      nombre = nom;
    }

    void setPrecio(float pre)
    {
      precio = pre;
    }

    void setStock(int stock)
    {
      this->stock=stock;
    }

    int getCodigo()
    {
      return codigo;
    }

    string getNombre()
    {
      return nombre;
    }

    float getPrecio()
    {
      return precio;
    }

    int getStock()
    {
      return stock;
    }

};
