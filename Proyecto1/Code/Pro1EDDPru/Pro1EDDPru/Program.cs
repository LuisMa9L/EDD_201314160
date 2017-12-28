using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pro1EDDPru
{
    class Program
    {
        static void Main(string[] args)
        {
            ArbolBB a = new ArbolBB();


            a.Insertar("no1", "Monoloc0", "corr");
            a.Insertar("no2", "XD", "corr");
            a.Insertar("no3", "cXD", "corr");
            a.Insertar("no30", "cXD", "corr");
            a.Insertar("no20", "cXD", "corr");
            a.Insertar("no", "cXD", "corr");
            a.Insertar("no25", "cXD", "corr");
            a.Buscar(a.Raiz, "no2").Juego.Inseretar("Daniel", 3, 4, 5, true);
            a.Buscar(a.Raiz, "no2").Juego.Inseretar("Josue", 3, 4, 5, true);
            a.Buscar(a.Raiz, "no1").Juego.Inseretar("Daniel", 3, 4, 5, true);
            a.Buscar(a.Raiz, "no1").Juego.Inseretar("Josue", 3, 4, 5, true);
            a.VerGraphviz();

            Console.ReadKey();

        }
    }
}
