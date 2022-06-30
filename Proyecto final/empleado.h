#include<string>
using namespace std;
class Empleado
{
  private:
      string usuario;
      int cod;
  public:
      Empleado()
      {
      }
      ~Empleado()
      {
      }
      void setUsuario(string usu)
      {
        usuario = usu;
      }

      void setCod(int cod)
      {
        this->cod=cod;
      }

      string getUsuario()
      {
        return this->usuario;
      }

      int getCod()
      {
        return this->cod;
      }
};
