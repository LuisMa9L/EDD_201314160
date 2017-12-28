using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Pro1EDDPru
{
    #region Arbol ABB
    class NodoABB
    {
        public NodoABB Derecha;
        public NodoABB Izquierda;
        public string Nickname;
        public string Contraseña;
        public string Correo;
        public bool Conectado;
        public Juego Juego;
        public NodoABB(string nick, string contraseña, string correo) {
            Derecha = null;
            Izquierda = null;
            Nickname = nick;
            Contraseña = contraseña;
            Correo = correo;
            Conectado = false;
            Juego = new Juego();
        }
    }
    class ArbolBB
    {
        public NodoABB Raiz;
        public void Insertar(string nick, string contraseña, string correo)
        {
            NodoABB nuevo = new NodoABB(nick, contraseña, correo);
            if (this.Raiz == null)
            {
                this.Raiz = nuevo;
            }
            else { 
                //Revisar si existe
                this.Insertar(this.Raiz, nuevo);
            }
        }
        public void Insertar(NodoABB actual, NodoABB nuevo)
        {
            if (actual != null)
            {
                string nik = actual.Nickname;
                string nnik = nuevo.Nickname;
                if (nik.CompareTo(nnik) == 1)//insertar izquierda
                {
                    if (actual.Izquierda == null)
                    {
                        actual.Izquierda = nuevo;
                    }
                    else
                    {
                        Insertar(actual.Izquierda, nuevo);
                    }
                }
                else if (nik.CompareTo(nnik) == -1)//insertar derecha
                {
                    if (actual.Derecha == null)
                    {
                        actual.Derecha = nuevo;
                    }
                    else
                    {
                        Insertar(actual.Derecha, nuevo);
                    }
                }
            }
        }
        public NodoABB Buscar(NodoABB actual, string nickp)
        {
            if (actual == null)
            {
                return null;
            }
            else
            {
                if (actual.Nickname.CompareTo(nickp) == 0) // se encontro
                {
                    return actual;
                }
                else//seguir buscando
                {
                    string nik = actual.Nickname;
                    string nnik = nickp;
                    if (nik.CompareTo(nnik) == 1)//buscar izquierda
                    {
                        if (actual.Izquierda != null)
                        {
                            return Buscar(actual.Izquierda, nickp);
                        }
                    }
                    else if (nik.CompareTo(nnik) == -1)//buscar derecha
                    {
                        if (actual.Derecha != null)
                        {
                            return Buscar(actual.Derecha, nickp);
                        }
                    }
                }
            }
            return null;
        }
        public NodoABB Sucesor(NodoABB encontrado)
        {
            NodoABB actual = encontrado.Derecha;
            while (actual.Izquierda != null)
            {
                actual = actual.Izquierda;
            }
            return actual;
        }
        public NodoABB BuscarPadre(string nick)
        {
            return BuscarPadre(this.Raiz,nick);
        }
        public NodoABB BuscarPadre(NodoABB actul, string nick)
        {
            if (actul != null)
            {
                if (actul.Nickname.CompareTo(nick) == 1)
                {
                    if (actul.Izquierda != null)
                    {
                        if (actul.Izquierda.Nickname.CompareTo(nick) == 0)// si es igual el hijo izquierdo
                        {
                            return actul;
                        }
                        else
                        {
                            return this.BuscarPadre(actul.Izquierda, nick);
                        }
                    }
                }
                else if (actul.Nickname.CompareTo(nick) == -1)
                {
                    if (actul.Derecha != null)
                    {
                        if (actul.Derecha.Nickname.CompareTo(nick) == 0)//igual al hijo derecho
                        {
                            return actul;
                        }
                        else
                        {
                            return this.BuscarPadre(actul.Derecha, nick);
                        }
                    }
                }
            }
            return null;
        }
        public void Eliminar(string nick)
        {
            NodoABB encontrado = this.Buscar(this.Raiz, nick);
            if (encontrado != null)
            {
                if (encontrado.Nickname.CompareTo(this.Raiz.Nickname) == 0)// si es la raiz
                {
                    if (this.Raiz.Derecha == null && this.Raiz.Izquierda == null)
                    {
                        this.Raiz = null;
                    }
                    else if (this.Raiz.Derecha == null && this.Raiz.Izquierda != null)
                    {
                        this.Raiz = this.Raiz.Izquierda;
                    }
                    else if (this.Raiz.Derecha != null && this.Raiz.Izquierda == null)
                    {
                        this.Raiz = this.Raiz.Derecha;
                    }
                    else if (this.Raiz.Derecha != null && this.Raiz.Izquierda != null)
                    {
                        NodoABB sucesor = this.Sucesor(encontrado);
                        string aux_nick = sucesor.Nickname;
                        encontrado.Correo = sucesor.Correo;
                        encontrado.Conectado = sucesor.Conectado;
                        encontrado.Contraseña = sucesor.Contraseña;
                        encontrado.Juego = sucesor.Juego;
                        this.Eliminar(sucesor.Nickname);
                        encontrado.Nickname = aux_nick;
                    }
                }
                else
                {
                    NodoABB padre = this.BuscarPadre(encontrado.Nickname);
                    bool enizquierda = false;
                    if (padre.Izquierda!= null)
                    {
                        if (padre.Izquierda.Nickname.CompareTo(encontrado.Nickname) == 0)
                        {
                            enizquierda = true;
                        }
                    }
                    if (encontrado.Izquierda == null && encontrado.Derecha == null)//nodo hoja
                    {
                        if (enizquierda)
                        {
                            padre.Izquierda = null;
                        }
                        else
                        {
                            padre.Derecha = null;
                        }
                    }
                    else if (encontrado.Izquierda != null && encontrado.Derecha == null)//solo hijo izquierda
                    {
                        if (enizquierda)
                        {
                            padre.Izquierda = encontrado.Izquierda;
                        }
                        else
                        {
                            padre.Derecha = encontrado.Izquierda;
                        }
                    }
                    else if (encontrado.Izquierda == null && encontrado.Derecha != null)//solo hijo derecha
                    {
                        if (enizquierda)
                        {
                            padre.Izquierda = encontrado.Derecha;
                        }
                        else
                        {
                            padre.Derecha = encontrado.Derecha;
                        }
                    }
                    else if (encontrado.Izquierda != null && encontrado.Derecha != null)//con 2 hijos
                    {
                        NodoABB sucesor = this.Sucesor(encontrado);
                        string aux_nick = sucesor.Nickname;
                        encontrado.Correo = sucesor.Correo;
                        encontrado.Conectado = sucesor.Conectado;
                        encontrado.Contraseña = sucesor.Contraseña;
                        encontrado.Juego = sucesor.Juego;
                        this.Eliminar(sucesor.Nickname);
                        encontrado.Nickname = aux_nick;

                    }
                }
            }
        }
        public void VerGraphviz()
        {
            String desktop;
            StringBuilder graphivz;
            graphivz = new StringBuilder();
            desktop = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
            String rutas = "";
            rutas = (desktop + "\\Files");
            if (!System.IO.Directory.Exists(rutas))
            {
                System.IO.DirectoryInfo dir = System.IO.Directory.CreateDirectory(rutas);
            }
            String rdot = desktop + "\\Files\\ListaDoble.dot";
            String rpng = desktop + "\\Files\\ListaDoble.png";
            graphivz.Append("digraph G {\r\nnode[shape=doublecircle, style=filled, color=khaki1, fontcolor=black]; \r\n");

            graphivz.Append(this.GenerarDatos(this.Raiz));
            graphivz.Append("}");

            System.IO.File.WriteAllText(rdot, graphivz.ToString());
            String comandodot = "dot.exe -Tpng " + rdot + " -o " + rpng + " ";
            var command = string.Format(comandodot);
            var procStartInfo = new System.Diagnostics.ProcessStartInfo("cmd", "/C" + command);
            var proc = new System.Diagnostics.Process();
            proc.StartInfo = procStartInfo;
            proc.Start();
            proc.WaitForExit();
            String rutas2 = rpng;
            if (!File.Exists(rutas2))
                return;

            try
            {
                System.Diagnostics.Process.Start(rutas2);
            }
            catch (Exception)
            {
                //Error :|
            }
        }
        public string GenerarDatos(NodoABB actual)
        {
            string enlaces = "";
            string etiquetas = "";
            if (actual != null)
            {
                etiquetas += "NAB_" + actual.Nickname + "[label=\"Nickname: " + actual.Nickname + "\\nCorreo: " + actual.Correo + "\\nPass: " + actual.Contraseña + "\"];\n";
                etiquetas += "subgraph Lista_de_"+actual.Nickname+"{\nnode[shape = circle, style = filled, color = khaki1, fontcolor = blue];\n";
                etiquetas += actual.Juego.GenerarDatos(actual.Juego.Principal,0,actual.Nickname);
                etiquetas += "}\n";
                if (actual.Juego.Principal != null)
                {
                    etiquetas += "NAB_" + actual.Nickname + " -> Juego1" + actual.Nickname + "\n";
                }
                if (actual.Izquierda != null)
                {
                    enlaces += "NAB_" + actual.Nickname + " -> NAB_" + actual.Izquierda.Nickname+";\n";
                    enlaces += GenerarDatos(actual.Izquierda);
                }
                if (actual.Derecha != null)
                {
                    enlaces += "NAB_" + actual.Nickname + " -> NAB_" + actual.Derecha.Nickname + ";\n";
                    enlaces += GenerarDatos(actual.Derecha);
                }
            }
            return etiquetas + enlaces;
        }
    }
    #endregion
    #region Listado Doble
    class NodoJuego
    {
        public NodoJuego Siguiente;
        public NodoJuego Anterior;
        public string Oponente;
        public int UDesplegadas;
        public int USobrevivientes;
        public int UDestruidas;
        public bool Gano;
        public NodoJuego(string oponente,int desplegadas, int sobrevivientes, int destruidas,bool gano){
            Siguiente = null;
            Anterior = null;
            Gano = gano;
            Oponente = oponente;
            UDesplegadas = desplegadas;
            USobrevivientes = sobrevivientes;
            UDestruidas = destruidas;
        }
    }
    class Juego
    {
        public NodoJuego Principal;
        public Juego()
        {
            Principal = null;
        }
        public void Inseretar(string oponente, int desplegadas, int sobrevivientes, int destruidas, bool gano) {
            NodoJuego nuevojuego = new NodoJuego(oponente, desplegadas, sobrevivientes, destruidas,gano);
            if (this.Principal == null)
            {
                Principal = nuevojuego;
            }
            else
            {
                nuevojuego.Siguiente = this.Principal;
                this.Principal.Anterior = nuevojuego;
                this.Principal = nuevojuego;
            }

        }
        public void VerGraphviz() {
            String desktop;
            StringBuilder graphivz;
            graphivz = new StringBuilder();
            desktop = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
            String rutas = "";
            rutas = (desktop + "\\Files");
                if (!System.IO.Directory.Exists(rutas))
                {
                    System.IO.DirectoryInfo dir = System.IO.Directory.CreateDirectory(rutas);
                }
            String rdot = desktop + "\\Files\\ListaDoble.dot";
            String rpng = desktop + "\\Files\\ListaDoble.png";
            graphivz.Append("digraph G {\r\n node[shape=doublecircle, style=filled, color=khaki1, fontcolor=black]; \r\n");

            //graphivz.Append(this.GenerarDatos(this.Principal, 0,));
            graphivz.Append("}");

            System.IO.File.WriteAllText(rdot, graphivz.ToString());
            String comandodot = "dot.exe -Tpng " + rdot + " -o " + rpng + " ";
            var command = string.Format(comandodot);
            var procStartInfo = new System.Diagnostics.ProcessStartInfo("cmd", "/C" + command);
            var proc = new System.Diagnostics.Process();
            proc.StartInfo = procStartInfo;
            proc.Start();
            proc.WaitForExit();
            String rutas2 = rpng;
            if (!File.Exists(rutas2))
                return;

            try
            {
                System.Diagnostics.Process.Start(rutas2);
            }
            catch (Exception)
            {
                //Error :|
            }
        }
        public String GenerarDatos(NodoJuego actual, int contador,string nick)
        {
            ++contador;
            String salidaEtiqueta = "";
            String salidaEnlace = "";
            if (actual != null)
            {
                salidaEnlace += "\tJuego" + contador + nick + "[label=\"Oponente " + actual.Oponente + "\\nDestruidas: " + actual.UDesplegadas + "\\nDesplegadas: " + actual.UDesplegadas + "\\nSobrevivieron: " + actual.USobrevivientes + "\"];\n";
                if (actual.Siguiente != null)
                {
                    int contador2 = contador + 1;
                    salidaEtiqueta += "\tJuego" + contador + nick + " -> Juego" + contador2 + nick + ";\n";
                    salidaEtiqueta += "\tJuego" + contador2 + nick + " -> Juego" + contador + nick + ";\n";
                }

                if (actual.Siguiente != null)
                {
                    salidaEtiqueta += this.GenerarDatos(actual.Siguiente, contador, nick);
                }
            }
            return salidaEnlace + salidaEtiqueta;
        }
    }
    #endregion
}
