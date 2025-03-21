#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
  private:
	Contact contacts[8]; // Tableau statique de 8 contacts
	int count;           // Nombre de contacts enregistrés
	int oldest;          // Index du plus ancien contact

  public:
	PhoneBook(); // Constructeur

	void addContact(); // Ajoute un contact
};