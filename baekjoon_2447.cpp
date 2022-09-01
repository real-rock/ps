/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_2447.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:47:23 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/01 14:47:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Site: baekjoon
// Problem id: 2447
// Algorithm: Divide and conquer

#include <iostream>
#include <vector>

int is_3pow(int n) {
	int k = 0;

	while (n != 0) {
		if (n % 3 != 0)
			break;
		n /= 3;
		k++;
		if (n == 1)
			break;
	}
	return k;
}

void check_blank(std::vector<std::vector<char>> &content, int i, int j, int size) {
	if (size == 0 || size == 1)
		return ;
	int s = size / 3;
	int tl_x = j + s;
	int tl_y = i + s;
	int br_x = tl_x + s;
	int br_y = tl_y + s;

	while (tl_y < br_y) {
		while (tl_x < br_x) {
			content[tl_y][tl_x] = ' ';
			tl_x++;
		}
		tl_x = j + s;
		tl_y++;
	}
	for (int n = 0; n < 9; n++) {
		int row = n / 3;
		int col = n % 3;
		if (row == 1 && col == 1)
			continue;
		check_blank(content, i + row * s, j + col * s, s);
	}
}

void print_stars(std::vector<std::vector<char>> &content) {
	for (auto &row: content) {
		for (auto &col: row) {
			std::cout << col;
		}
		std::cout << '\n';
	}
}

int main() {
	using namespace std;
	int n;
	vector<vector<char>> content;
	cin >> n;
	int k = is_3pow(n);
	if (k <= 0 || k > 7)
		return 1;
	content.resize(n);
	for (auto &c: content) {
		c.resize(n, '*');
	}
	check_blank(content, 0, 0, n);
	print_stars(content);
	content.clear();
}
