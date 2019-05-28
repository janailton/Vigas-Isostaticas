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


#include "Viga.h"

viga_isostatica::viga_isostatica( double comprimento_do_vao , int numero_de_apoios )
:	m_comprimento_do_vao( comprimento_do_vao )
{
	definir_numero_de_apoios( numero_de_apoios );
}

viga_isostatica::~viga_isostatica()
{

}

void viga_isostatica::definir_numero_de_apoios( int apoios )
{
	m_numero_de_apios = apoios;
	for( int i=0; i< apoios; i++)
    	reacao_no_apoio.push_back( 0 );
}

double viga_isostatica::obter_numero_de_apoios()
{
	return m_numero_de_apios;
}

double viga_isostatica::obter_comprimento_do_vao()
{
	return m_comprimento_do_vao;
}

void viga_isostatica::adicionar_carga( Carga * q )
{
	/*
	int num_minicargas = q->existe_minicarga();
	if( num_minicargas > 0 )
	{
		std::vector< Carga *> temp = q->obter_minicarga();
		for( int i=0; i< num_minicargas; i++)
			carga.push_back( temp[i] );
	}
	else carga.push_back( q );
	*/

	carga.push_back( q );
}

std::vector< Carga *> viga_isostatica::processar_cargas()
{
	std::vector< Carga *> q;
	for( size_t i = 0; i < carga.size() ; i++)
	{
		int num_minicargas = carga[i]->existe_minicarga();
		if( num_minicargas > 0 )
		{
			std::vector< Carga *> temp = carga[i]->obter_minicarga();
			for( int j=0; j< num_minicargas; j++)
				q.push_back( temp[j] );
		}
		else q.push_back( carga[i] );
	}

	return q;
}

void viga_isostatica::deletar_cargas()
{

	std::for_each( carga.begin(), carga.end(), deletar_carga );
	carga.clear();
}

void viga_isostatica::remover_carga( const int & i )
{
	std::vector< Carga *>::iterator it;
	it = std::find( carga.begin() , carga.end() , carga[i] );
	carga.erase( it );
}

void viga_isostatica::remover_cargas()
{
	carga.clear();
}

int viga_isostatica::calcular_reacoes()
{
	try
	{
		reacao_no_apoio[0] = 0;
		reacao_no_apoio[1] = 0;

		std::vector< Carga *> carga_processada = processar_cargas();

		// reação no primeiro apoio

		for( size_t i = 0; i < carga_processada.size() ; i++)
			reacao_no_apoio[0] += carga_processada[i]->obter_carga() * ( ( obter_comprimento_do_vao() - carga_processada[i]->obter_cota() )/obter_comprimento_do_vao() );

		// reação no segundo apoio
		reacao_no_apoio.push_back( 0 );
		for( size_t i = 0; i < carga_processada.size() ; i++)
			reacao_no_apoio[1] += carga_processada[i]->obter_carga();
		reacao_no_apoio[1] -= reacao_no_apoio[0]; // B = B -A

		return 1; // retorna 1 se não houveram erros
	}
	catch( ... )
	{
		return 0; // retorn 0 se houveram erros
	}
}

//!!! deve ser chamado primero viga_isostatica::calcular_reacoes() 
double viga_isostatica::obter_reacao( int apoio )
{
	return reacao_no_apoio[apoio];
}

//!!! deve ser chamado primero viga_isostatica::calcular_reacoes() 
double viga_isostatica::cortante( const double & x )
{
	std::vector< Carga *> carga_processada = processar_cargas();

    // se a cota de x está além do fim do ultimo apoio, retorna zero
	if( x > carga_processada[carga_processada.size() - 1 ]->obter_cota() && x > this->obter_comprimento_do_vao()  )
		return 0;

	double corte = 0;

	for( size_t i = 0; i < carga_processada.size() ; i++)
	{
		if( x - carga_processada[i]->obter_cota() < 0 )
			continue;
		else
			corte -= carga_processada[i]->obter_carga();
	}

	if( x > 0 )
		corte += obter_reacao( 0 );
	if( x > obter_comprimento_do_vao() )
				corte += obter_reacao( 1 );

	return corte;
}

//!!! deve ser chamado primero viga_isostatica::calcular_reacoes() 
double viga_isostatica::momento( const double & x )
{

	std::vector< Carga *> carga_processada = processar_cargas();

    // se a cota de x está além do fim do ultimo apoio, retorna zero
	if( x > carga_processada[carga_processada.size() - 1 ]->obter_cota() && x > this->obter_comprimento_do_vao()  )
		return 0;

	double momento_fletor = 0;

	for( size_t i = 0; i < carga_processada.size() ; i++)
	{
		if( x - carga_processada[i]->obter_cota() < 0 )
			continue;

		momento_fletor -= carga_processada[i]->obter_carga() * ( x - carga_processada[i]->obter_cota() );
	}

	if( x > 0 )
		momento_fletor += ( obter_reacao( 0 ) * x );
	if( x > obter_comprimento_do_vao() )
				momento_fletor += obter_reacao( 1 ) * ( x - obter_comprimento_do_vao() );

	return momento_fletor;
}