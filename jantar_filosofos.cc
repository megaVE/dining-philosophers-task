#include <iostream>
using namespace std;

/*
 *  JANTAR DOS FILÓSOFOS
 * Convidados:  
 * 
 *  1 - Ludwig
 *  2 - Wilhelm
 *  3 - Cleiton
 *  4 - Aristóteles
 *  5 - Agostinho
 * 
 * Mapa da Mesa:
 *  (5) (1)
 * (4)   (2)
 *    (3)
 *
 *
 *
 *  ESTRATÉGIA DE RESOLUÇÃO
 * 
 *  Por um momento: um par de filósofos come enquanto o restante pensa.
 *  Logo em seguida: a fila progride e os filósofos que comiam e pensavam são trocados.
 *  Isso garante que em a todo ciclo, todos os filósofos terão, entre si, o mesmo tempo de comer e pensar.
 */

string nome(int codigo){ // Função Auxiliar da Função de Impressão
    switch(codigo){
        case 0:
         return "Ludwig";
         
        case 1:
         return "Wilhelm ";

        case 2:
         return "Cleiton";

        case 3:
         return "Aristóteles";

        case 4:
         return "Agostinho";

        default: // Técnicamente, não seria necessária declaração de default neste caso
         return "";
    }
}

void imprime(int *comendo){ // Função que Imprime um Determinado Cenário da Mesa dos Filósofos
    for(int i = 0; i < 5; i++){
        if(i == comendo[0] || i == comendo[1])
            cout << nome(i) << " está comendo" << endl;
        else
            cout << nome(i) << " está pensando"<< endl;
    }
    cout << endl << "--- --- ---" << endl << endl;
}

char icone(int *comendo, int codigo){ // Função Auxiliar daquela que Imprime a Mesa
    if(codigo == comendo[0] || codigo == comendo[1])
        return 'x';
    else
        return 'o';
}

void imprime_mesa(int *comendo){ // Função Geradora de Representação Visual da Mesa
    cout << "\t (" << icone(comendo, 4) << ") (" << icone(comendo,0) << ")" << endl << "\t(" << icone(comendo,3) << ")   (" << icone(comendo,1) << ")" << endl << "\t   (" << icone(comendo,2) << ")" << endl << endl;
}

int main (void){
    int comendo[2]; // O vetor contem, em cada um de seus elementos, um dos filósofos que está comendo no determinado momento
    int fila[5] = {14, 25, 13, 24, 35}; // O vetor contem a listagem de cenários possíveis
    for(int i = 0; 1; i++){
        if(i == 5) // A fila será reiniciada caso alcance seu limite
            i = 0;
        comendo[0] = fila[i] % 10 - 1; // Pelo vetor fila, determina-se quais filósofos podem estar comendo em um determinado momento
        comendo[1] = fila[i] / 10 - 1;
        imprime_mesa(comendo);
        imprime(comendo);
    }
    return 0;
}