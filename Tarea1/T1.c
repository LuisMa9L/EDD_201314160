

struct Nodo
{
    int valor;
    Nodo *Siguiente;
};
struct Lista {
  Nodo *Cabecera;
  Nodo *Final;
};

typedef Nodo Nodo;
typedef Lista Lista;

int main()
{
    return 0;

}

void insertar (Lista  * lista_,int valor_){
    Nodo * nuevo = malloc(sizeof(Nodo));
    nuevo->valor=valor_;
    if (lista_->Cabecera == NULL) {
        lista_->Cabecera = nuevo;
        lista_->Final = nuevo;
        return;
    }
    lista_->Final->Siguiente = nuevo;
    lista_->Final = nuevo;
}

void eliminar(Lista  * lista_,int valor_){
    if (lista_==NULL) return;
    Nodo * actual = lista_->Cabecera;
    while (actual->Siguiente != nullptr) {
        if (actual->Siguiente->valor == valor_) {
            Nodo * n = actual->Siguiente;
            actual->Siguiente = actual->Siguiente->Siguiente;
            free(n);
            return;
        }
        actual = actual->Siguiente;
    }
}
