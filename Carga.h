/*
 *  Copyright (C) 2010  José Janaílton da Silva
 *	<josejanailton@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef __CARGA_H__
#define __CARGA_H__

#include <vector>

#ifndef NULL
#define NULL 0
#endif

class Carga
{
public:
	Carga(void){	};
	virtual ~Carga(void){	};

	virtual void definir_carga( double q ) = 0;
	virtual void definir_cota( double c ) = 0;

	virtual double obter_carga() = 0;
	virtual double obter_cota() = 0;

	// Pode ser útil dividir uma carga em cargas menores,
	// como é o caso das cargas distribuídas
	// a função existe_minicarga() retorna o número de minicargas "existentes"
	virtual int existe_minicarga() = 0;
	// Preenche o objeto q com as minigargas
	virtual std::vector< Carga *> obter_minicarga() = 0;

};

class carga_concentrada : public Carga
{
public:
	carga_concentrada();
	carga_concentrada( double carga , double cota );
	virtual ~carga_concentrada();

	virtual void definir_carga( double q );
	virtual void definir_cota( double c );

	virtual double obter_carga();
	virtual double obter_cota();

	virtual int existe_minicarga() { return 0; };
	virtual std::vector< Carga *> obter_minicarga() {	std::vector< Carga *> f; return f; };

protected:
	double m_carga;
	double m_cota;
};

class carga_distribuida :public carga_concentrada
{
public:
	carga_distribuida( const double & carga , const double & cota_inicial_da_carga , const double & comprimento );
	virtual ~carga_distribuida();

	virtual void definir_comprimento( double comprimento );
	virtual double obter_comprimento();
	virtual void definir_quantidade_minicargas( int quantidade = 100 );
	virtual int existe_minicarga();
	virtual std::vector< Carga *> obter_minicarga();

protected:
	int quantidade_minicargas;
	double m_comprimento;
};



#endif __CARGA_H__