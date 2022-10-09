/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_2263.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:29:39 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/08 14:38:51 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Site: baekjoon
 Problem id: 2263
 Algorithm: Divide and conquer
 URL: https://www.acmicpc.net/problem/2263
*/

#include <iostream>
#include <vector>

using namespace std;

void in_traversal(vector<int> &in, vector<int> &pre, int parent) {
	if (parent >= in.size())
		return;
	in_traversal(in, pre, parent * 2); // travel left
	pre[parent] = in[parent];
	in_traversal(in, pre, parent * 2 + 1); // travel right
}

void get_pre(vector<int> &post, vector<int> &in, vector<int> &pre) {
	
}

int main() {
	int n;
	vector<int> post(n, 0), in(n, 0), pre(n, -1);
	cin >> n;
	for (auto &p: post)
		cin >> p;
	for (auto &i: in)
		cin >> i;
	get_pre(post, in, pre);
	for (auto &p: pre)
		cout << p << ' ';
	cout << '\n';
}
