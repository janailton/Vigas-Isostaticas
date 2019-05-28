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


#include "Carga.h"

/****** Implementação da classe carga_concentrada *******/

carga_concentrada::carga_concentrada()
{

}

carga_concentrada::carga_concentrada( double carga , double cota )
{
	definir_carga( carga );
	definir_cota( cota );
}

carga_concentrada::~carga_concentrada()
{

}

void carga_concentrada::definir_carga( double q )
{
	m_carga = q;
}

void carga_concentrada::definir_cota( double c )
{
	m_cota = c;
}

double carga_concentrada::obter_carga()
{
	return m_carga;
}
double carga_concentrada::obter_cota()
{
	return m_cota;
}


/********** Implementação da classe carga_distribuida ************/

carga_distribuida::carga_distribuida(const double & carga , const double &cota_inicial_da_carga, const double &comprimento)
:  carga_concentrada( carga , cota_inicial_da_carga ) 
{
	definir_comprimento( comprimento );
	definir_quantidade_minicargas();
}

carga_distribuida::~carga_distribuida()
{

}

void carga_distribuida::definir_comprimento( double comprimento )
{
	m_comprimento = comprimento;
}

double carga_distribuida::obter_comprimento()
{
	return m_comprimento;
}

void carga_distribuida::definir_quantidade_minicargas(int quantidade)
{
	quantidade_minicargas = quantidade;
}

int carga_distribuida::existe_minicarga()
{
	return quantidade_minicargas;
}

std::vector< Carga *> carga_distribuida::obter_minicarga()
{

	double x = obter_cota(); 
	double ext = obter_comprimento(); 
	double acrescimo = ext/quantidade_minicargas; 
	x += acrescimo/2; 
	double q = (obter_carga() / 100); // conversão para Kg/cm 
	q = q*(obter_comprimento()/quantidade_minicargas); 

	std::vector<Carga *> carga;

	for( int i = 0; i < quantidade_minicargas; i++)
	{		
		carga.push_back( new carga_concentrada( q , x ) ); 
		x += acrescimo;	
	}
	return carga;

}