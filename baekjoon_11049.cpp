/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_11049.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:39:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/10 08:28:36 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Site: baekjoon
Problem id: 11049
Algorithm: Dynamic programming
Description:
    행렬 곱셈 순서 구하기
URL: https://www.acmicpc.net/problem/11049
*/

#include <vector>
#include <iostream>

int dp(std::vector<int> &d) {
    int size = d.size() - 1;
    std::vector<std::vector<int>> m(size, std::vector<int>(size, 0));
    for (int dt = 1; dt < size; dt++) {
        for (int i = 0; i < size - dt; i++) {
            int j = i + dt;
            int min = 2147483647;

            for (int k = i; k < j; k++) {
                int v = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                min = min < v ? min : v;
            }
            m[i][j] = min;
        }
    }
    return m[0][size - 1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> d(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        d[i] = a;
        if (i == n - 1)
            d[i + 1] = b;
    }
    std::cout << dp(d) << std::endl;
}