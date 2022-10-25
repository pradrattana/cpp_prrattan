/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:37:22 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/25 12:37:23 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <exception>

template <typename T>
typename T::iterator	easyfind(T &container, int needle) {
	typename T::iterator	it;

	it = find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw "Element not found";
	return (it);
}

#endif
