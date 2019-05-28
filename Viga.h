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


#ifndef __VIGA_H__
#define __VIGA_H__

#include "carga.h"
#include <vector>
#include <algorithm>

class Viga
{
public:
	Viga(void)	{	};
	virtual ~Viga(void)	{	};

	virtual void definir_numero_de_apoios( int apoios = 2 ) = 0;
	virtual double obter_numero_de_apoios() = 0;
	virtual double obter_comprimento_do_vao() = 0;

	virtual void adicionar_carga( Carga * q) = 0;

	virtual void remover_carga( const int & i ) = 0;
	// remove as cargas sem limpar a memória
	// i.e. sem usar o comando delete nos ponteiros
	virtual void remover_cargas() = 0;
	// remove as cargas, limpando a memória
	virtual void deletar_cargas() = 0;

	virtual int calcular_reacoes() = 0;
	// uma viga poder mais de dois apoios, então...
	// os apoios são contados apartir de zero, então o apoio zero = apoio_A
	virtual double obter_reacao( int apoio ) = 0;

	// esforço cortante em um ponto x da viga
	virtual double cortante( const double & x ) = 0;
	// momento em um ponto x da viga
	virtual double momento( const double & x ) = 0;

protected:

	static void deletar_carga( Carga * q )
	{
		delete q;
	}

};

class viga_isostatica : public Viga
{
public:
	viga_isostatica( double comprimento_do_vao , int numero_de_apoios = 2 );
	virtual ~viga_isostatica();

	virtual void definir_numero_de_apoios( int apoios = 2 );
	virtual double obter_numero_de_apoios();
	virtual double obter_comprimento_do_vao();

	virtual void adicionar_carga( Carga * q);
	virtual void remover_cargas();
	virtual void remover_carga( const int & i );

	virtual int calcular_reacoes();
	// uma viga poder mais de dois apoios, então...
	// os apoios são contados apartir de zero, então o apoio zero = apoio_A
	virtual double obter_reacao( int apoio );

	// esforço cortante em um ponto x da viga
	virtual double cortante( const double & x );
	// momento em um ponto x da viga
	virtual double momento( const double & x );

protected:
	std::vector< Carga *> carga;
	std::vector< double > reacao_no_apoio;
	
	int m_numero_de_apios;
	double m_comprimento_do_vao;

	virtual std::vector< Carga *> processar_cargas();
	virtual void deletar_cargas();
};


#endif