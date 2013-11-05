all:
	g++ -Wall main.cpp condominium.cpp corporation.cpp maintenance.cpp menu.cpp owner.cpp property.cpp worker.cpp -o AEDA

clean:
	rm -rf *o AEDA
