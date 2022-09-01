/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_1074.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:45:42 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/01 16:07:06 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Site: baekjoon
// Problem id: 1074
// Algorithm: Divide and conquer
// URL: https://www.acmicpc.net/problem/1074

#include <iostream>
#include <vector>
#define LL long long

using namespace std;

LL divide_conquer(int r, int c, int size) {
	static int base[2][2] = {{0, 1}, {2, 3}};
	if (r < 2 && c < 2)
		return base[r][c];
	int d_size = size / 2;
	if (r < d_size && c < d_size) { // Top Left corner
		return divide_conquer(r, c, d_size);
	}
	else if (r < d_size && c >= d_size) { // Top Right corner
		return divide_conquer(r, c - d_size, d_size) + d_size * d_size;
	}
	else if (r >= d_size && c < d_size) { // Bottom Left corner
		return divide_conquer(r - d_size, c, d_size) + d_size * d_size * 2;
	}
	else { // Bottom Right corner
		return divide_conquer(r - d_size, c - d_size, d_size) + d_size * d_size * 3;
	}
}

int pow(int n) {
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= 2;
	return res;
}

int main() {
	int n, r, c;
	vector<vector<char>> content;
	cin >> n >> r >> c;
	cout << divide_conquer(r, c, pow(n)) << '\n';
}
