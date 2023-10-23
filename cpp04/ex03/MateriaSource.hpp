/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:49 by sutku             #+#    #+#             */
/*   Updated: 2023/10/23 14:06:10 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#ifndef MATERIASOURCE_HPP
#define MATERISOURCE_HPP

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &copy);
		virtual ~MateriaSource();
	
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const &type);
};

#endif