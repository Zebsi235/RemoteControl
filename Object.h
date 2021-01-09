/////////////////////////////
// Workfile : Object.h
// Author : Pascal Lang
// Date : 12.12.2020
// Description : Base Class.
/////////////////////////////

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

//Basis aller Basisklassen
class Object
{
public:
	virtual ~Object() = default;

protected:
	//Default-CTor: Benutzer kann kein Object erzeugen
	Object() = default;

};

#endif // OBJECT_H
