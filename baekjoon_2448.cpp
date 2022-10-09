/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_2448.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:07:54 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/01 16:14:58 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Site: baekjoon
 Problem id: 2448
 Algorithm: Divide and conquer
 URL: https://www.acmicpc.net/problem/2448
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<vector<char>> content;
	int n, k;
	cin >> n;
	k = -1;
	if (n % 3 != 0)
		return 1;
	n /= 3;
	while (n) {
		k++;
		n /= 2;
	}
	int row = 3 * int(pow(2.0, k));
	int col = 6 * int(pow(2.0, k)) - 1;
	content.resize(row, vector<char>(col, '*'));
}
