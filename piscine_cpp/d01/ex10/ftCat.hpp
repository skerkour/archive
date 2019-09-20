/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftCat.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 19:59:05 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 20:28:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

namespace ftCat
{
void	readByLine(std::ifstream& inFile);
void	readFile(std::string filename);
void	readFiles(char** files);
void	readStandardEntry();
}
