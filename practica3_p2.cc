void InsertionSort(int values[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            --j;
        }

        values[j + 1] = key;
    }
}

void InsertionSort2(int values[], int size, int start, int end) {
  if (start < 0 || end >= size || start >= end) {
    return;
  }

  for (int i = start + 1; i <= end; ++i) {
    int key = values[i];
    int j = i - 1;

    while (j >= start && values[j] > key) {
      values[j + 1] = values[j];
      --j;
    }

    values[j + 1] = key;
  }
}

int BinarySearch(const int values[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (values[mid] == target) {
      return mid;
    }

    if (values[mid] < target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int BinarySearch2(const int values[], int size, int target) {
  int left = 0;
  int right = size - 1;
  int result = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (values[mid] == target) {
      result = mid;      // candidato a primera aparición
      right = mid - 1;   // seguir buscando a la izquierda
    } 
    
    else if (values[mid] < target) {
      right = mid - 1;
    } 
    
    else {
      left = mid + 1;
    }
  }

  return result;
}

/*Pregunta: ¿por qué no basta con retornar mid en cuanto se encuentra el valor buscado?
Porque el arreglo puede tener valores repetidos, y la búsqueda binaria cae en una posición cualquiera dentro del grupo de
repetidos, no necesariamente en la primera. Por ejemplo, con target = 7 el primer mid es 3, que es la tercera aparición 
del 7, no la primera (índice 1). Si retornáramos mid de inmediato, devolveríamos un índice correcto en cuanto a que 
contiene el 7, pero no el que pide el problema. Por eso, al encontrar el valor se guarda la posición y se continúa 
buscando en la mitad izquierda, donde podría haber una aparición anterior. La complejidad se mantiene en O(log n), 
porque en cada vuelta se sigue descartando la mitad del rango.

Pregunta: ¿por qué el ciclo externo debe comenzar en start + 1 y no en 1?
En insertion sort, el primer elemento del rango se considera un subarreglo ya ordenado de tamaño 1, y a partir del 
segundo se van insertando los demás en su lugar. En el algoritmo original ese primer elemento es values[0], por eso el 
ciclo empieza en 1. Al ordenar solo un segmento, el primer elemento del segmento es values[start], así que el primero 
que hay que insertar es values[start + 1]. Si el ciclo empezara en 1, se procesarían elementos que están fuera del 
segmento (a la izquierda de start), lo que modificaría posiciones que no deben tocarse y daría un resultado incorrecto. 
Además, el while debe usar j >= start por la misma razón: los desplazamientos nunca deben cruzar el límite izquierdo del 
segmento.*/