#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this!= NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int lenList= ll_len(this);
    int i;
    if(this!=NULL && nodeIndex>=0 && nodeIndex< lenList)
    {
        pNode=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
            {
                pNode=pNode->pNextNode;
            }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode= malloc(sizeof(Node));
    Node* pNode= NULL;

    pNewNode->pElement=pElement;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<= this->size && pNewNode!= NULL)
        {
            if(nodeIndex==0)
            {
            pNewNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNewNode;
            this->size++;
            returnAux=0;
            }
            else
            {
                pNode=getNode(this,nodeIndex-1);
                pNewNode->pNextNode=pNode->pNextNode;
                pNode->pNextNode=pNewNode;
                this->size++;
                returnAux=0;
            }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && addNode(this,this->size,pElement)==0)
    {
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int nodeIndex)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<=this->size)
    {
        pNode=getNode(this,nodeIndex);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<this->size)
    {
        returnAux=0;
        pNode=getNode(this,nodeIndex);
        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int nodeIndex)
{
    int returnAux = -1;
    Node* pNodeA;
    Node* pNodeB;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<this->size)
    {
        returnAux=0;
        if(this->size==1)
        {
            this->pFirstNode=NULL;
            this->size--;
            pNodeA=getNode(this,nodeIndex);
            free(pNodeA);
        }
        else
        {
            pNodeA=getNode(this,nodeIndex);
            if(pNodeA!=NULL)
            {
                pNodeB=getNode(this,nodeIndex-1);
                pNodeB->pNextNode=pNodeA->pNextNode;
                this->size--;
                free(pNodeA);
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* pNodeA;
    Node* pNodeB;
    int i;
    if(this!= NULL)
    {
        if(this->size==0)
        {
            returnAux = 0;
        }
        else
        {
            for(i=0;i<this->size;i++)
            {
                pNodeA=getNode(this,i);
                if(pNodeA!=NULL)
                {
                    pNodeB=pNodeA->pNextNode;
                    free(pNodeA);
                }
            }
            free(pNodeB);
            returnAux =0;
        }
        this->size=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int i;
    if(this!=NULL)
    {
        for(i=0;i<this->size;i++)
        {
            pNode=getNode(this,i);
            if(pNode!= NULL && pNode->pElement==pElement )
            {
                returnAux=i;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux = 1;
        }
       else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<=this->size && addNode(this,nodeIndex,pElement)==0)
    {
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<this->size)
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL )
    {
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* aux;
    int limite2;
    if(this != NULL && this2 != NULL)
    {
        limite2=this2->size;
        if(this==this2)
            {
                returnAux = 1;
            }
        else
        {
            for(i=0;i<limite2;i++)
            {
                aux=ll_get(this2,i);
                if(ll_contains(this,aux)==0)
                    {
                        break;
                    }
            }
        }
        if(i==limite2)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int j;
    Node* pNode;

    if(this!=NULL && from>=0 && to<=this->size && from<to)
    {
        cloneArray=ll_newLinkedList();
        for(i=from,j=0;i<to;i++,j++)
        if(cloneArray!=NULL)
        {
            {
                pNode=getNode(this,i);
                j=addNode(cloneArray,j,pNode->pElement);
            }
        }
    }
    else
    {
        cloneArray = NULL;
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;
    if (this!= NULL)
    {
        cloneArray=ll_newLinkedList();
        for (i=0;i<this->size;i++)
        {
                if(cloneArray!=NULL)
            {
                {
                    pNode=getNode(this,i);
                    addNode(cloneArray,i,pNode->pElement);
                }
            }

        }
    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    Node* pNode;
    Node* pNextNode;
    void* aux;
    int flag;
    int i;
    if (this!=NULL && pFunc!=NULL &&(order==1 || order==0) && this->size>0)
    {
        do
        {

            flag =0;
            pNode=this->pFirstNode;

            if(pNode!=NULL)
            {
                printf("ESTOY");
                pNextNode=pNode->pNextNode;

                for (i=0; i<this->size; i++)
                {
                    if(((pFunc(pNode->pElement,pNextNode->pElement))==1 && order==1) ||
                        ((pFunc(pNode->pElement,pNextNode->pElement))==-1 && !order))
                    {
                        printf("ESTOY EN EL IF DEL FOR\n");
                        flag=1;
                        aux=pNode->pElement;
                        pNode->pElement=pNextNode->pElement;
                        pNextNode->pElement=aux;
                    }
                    if (pNode->pElement!=NULL)
                    {
                        printf("IF DEL PNODE PARA AVANZAR");
                        pNode=pNextNode;
                        break;
                    }
                    else
                    {
                        pNextNode=pNextNode->pNextNode;
                        break;
                    }
                }


            }

        }
        while(flag);




}
return returnAux;
}
