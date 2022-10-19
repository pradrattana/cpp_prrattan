/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:28 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/19 13:29:33 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T	max(T &x, T &y) {
	return (x > y ? x : y);
}

template <typename T>
T	min(T &x, T &y) {
	return (x < y ? x : y);
}

template <typename T>
void	swap(T &x, T &y) {
	T	temp = x;
	x = y;
	y = temp;
}

#endif
