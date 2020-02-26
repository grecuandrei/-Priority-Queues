		Copyright @ 2019 Grecu Andrei-George - 325CA, All rights reserved


		Analiza Algoritmilor - Etapa a 2-a

	algo.cpp / algo2.cpp

		Acestea contin implementarea algoritmilor structurilor de date alese: AVL tree, respectiv Max Heap.
	
	algo.cpp : 
		Contine implementarea pentru AVL tree.

		Sunt implementate metode ca: inserare de cheie, stergere de cheie, gasirea minimului/maximului si
		cele specifice AVL-ului: rotiri (stanga, dreapta, stanga apoi dreapta, dreapta apoi stanga),
		rebalansarea si inaltimea unui nod in arbore.

	algo2.cpp : 
		Contine implementarea pentru Max Heap.

		Acesta este tinut intr-un array, considerand ca aceasta metoda este mai rapida.

		Sunt implementate metode ca: inserare de cheie, stergere de cheie, dar si specifice ca: extragerea
		maximului si eliminarea lui, top (returneaza doar maximul din heap), heapify_up, heapify_down,
		returnarea parintelui, copilului stanga si dreapta.

	algo_test.cpp :

		Fisierul va citi datele de intrare corespunzatoare testelor, de la 1 la 9, din linia de comanda
	cu ajutorul comenzii "./tester testID.in testID.out", va utiliza algoritmul 1, AVL, pentru a introduce datele
	in acesta si se va intoarce maximul si minimul, apoi stergandu-le din arbore (2 delete-uri) intr-o iteratie de for.

		Rezultatele vor fi scrise in fisierul testID.out astfel:

		NrElemente nr inserate in AVL tree
		NrOperatia Max: rez Min: rez
			unde rez este rezultatul operatiei getMax, respectiv getMin

		Pentru a vizualiza ref-urile facute local, personal, pentru acest algoritm accesati folderul corespunzator:
			out/ref_algo

	algo2_test.cpp :

		Fisierul va citi datele de intrare corespunzatoare testelor, de la 1 la 9, din linia de comanda
	cu ajutorul comenzii "./tester testID.in testID.out", va utiliza algoritmul 2, Max Heap, pentru a introduce datele
	in acesta si sa intoarca maximul, respectiv stergandu-l.

		Rezultatele vor fi scrise in fisierul testID.out astfel:

		NrElemente nr inserate in Max Heap
		NrOperatia Max: rez
			unde rez este rezultatul operatiei getMax

		Pentru a vizualiza ref-urile facute local, personal, pentru acest algoritm accesati folderul corespunzator:
			out/ref_algo2

	Makefile:
		crearea fisierului tester ce va fi executabilul de testare pentru algortmul ales pentru testare

		build_best: comanda de build pentru algoritmul 1 si algo_test corespunzator

		build_snd_best: comanda de build pentru algoritmul 2 si algo2_test corespunzator

	Teste:
		9 Teste cu numere din Z, cu marime variabila, generate pseudo-random, pentru a teste la maximum
		cozile de prioritate implementate. Acestea se afla in folderul in.

		Acestea sunt de forma:
			M N {secventa}
				unde M - numarul de outputuri/delete-uri (in functie de coada aleasa)
				     N - numarul de inserturi
				     {secventa} - secventa de N numere intregi pentru inserare in structura

		testID.in : ID-ul inseamna puterea a lui 10 (deci test7.in e 10^7 elemente), iar ultimele doua teste (8, 9)
			au 15*10^5, respectiv 2*10^6 elemente.

		Numarul de operatii variaza la fiecare test.

		Pentru vizualizarea generatorului de teste, l-am introdus si pe acesta in arhiva sub numele de: test_generator.cpp.

	Mentionez ca m-am inspirat din codul personal scris la Structuri de Date anul trecut si ca am folosit site-uri precum:
		http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Trees/AVL-delete.html
		https://rosettacode.org/ (took height (depth in site) and modify it for my implementation)
		https://codereview.stackexchange.com/ (took delete method from avl, but optimize it)
		https://github.com/
	pentru referinte si idei de cod optimizat.


