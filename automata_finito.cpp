#include <iostream>
#include <string.h>

#include <vector>

class nodo
{
    bool validacion;
    int * comportamiento;
    int num;
public:
	nodo()
	{
		validacion = false;
	}
	
	void creacion_nodo(std::string alfabeto, int nodos)
	{
		comportamiento = new int [alfabeto.size()];
		num = alfabeto.size();
		for (int i  = 0; i < num; i++)
			while(true)
			{
				std::cout << "seleccione el estado al que respondera este con el caracter " << alfabeto[i] << " \n";
				std::cin >> comportamiento[i];
				if (comportamiento[i] < nodos && comportamiento[i] >=0 )
					break;
				else
					std::cout << "estado inexistente, pruebe otro\n";
			}
		int valid;
		std::cout << "¿ este es un estado final (de validacion) ?  si (1) no (cualquier otro boton) "  ;
		std::cin >> valid;
		if(valid == 1)
			validacion = true;
	}
	
	friend class automata_finito;
};

class automata_finito
{
    std::string alfabeto;
    std::vector<nodo> nodos;
    int nodo_Actual;
public:
	automata_finito()
	{
		nodo n;
		int num;
		std::cout << "escriba el alfabeto que sera reconocido por el automata finito: ";
		std::cin >> alfabeto;
		std::cout << "\n\nescoge cuantos estados tendra el automata finito: ";
		std::cin >> num;
		
		for(int i  = 0; i < num ; i++)
			nodos.push_back(n);
		std::cout << "es hora de definir los estados, estos seran reconocidos por su orden. \n";
		for(int i = 0; i < nodos.size();i++){
			std::cout << "estado numero "<< i<< " inserte los datos: \n"; 
			nodos[i].creacion_nodo(alfabeto, num);	
		}
		std::cout << "automata finito completo, listo para recibir cadenas, el nodo inicial es 0\n";
		nodo_Actual = 0;
	}
	
	bool cadena_alfabeto(std::string cadena)
	{
		int j;
		for(int i = 0; i < cadena.size(); i++){
			j = 0;
			while(alfabeto[j] != cadena[i]){
				j++;
				if(j > alfabeto.size())
					return false;
				}
		}
		return true;
	}
	
	void validar_cadena(std::string cadena)
	{
		int aux=0;
		if(cadena_alfabeto(cadena))
		{
			std::cout << "cadena apta..\n";
			for(int i  = 0; i < cadena.size(); i++)
			{
				for(int j = 0; j < alfabeto.size(); j++)
				{
					if(alfabeto[j]==cadena[i])
						aux = j;
				}
				nodo_Actual = nodos[nodo_Actual].comportamiento[aux];
			}
			std::cout << "estado final: "<<nodo_Actual<< "\n";
			if(nodos[nodo_Actual].validacion)
				std::cout<< "cadena validada, \n";
			else 
				std::cout << "cadena invalidada,\n ";
			nodo_Actual = 0;
		}
		else
			std::cout << "cadena tiene uno o mas caracteres que no concuerdan con el alfabeto del automata\n";
	}
	
};

int main()
{
	automata_finito aut;
	
	std::cout << "con el automata, ahora podras insertar cadenas y ver si las valida o no \n";
	std::string cadena;
	
	while(true)
	{
		std::cout << "\n escriba su cadena...   ";
		std::cin >> cadena;
		aut.validar_cadena(cadena);
	}
}
