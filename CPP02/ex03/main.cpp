/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:03:36 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/21 21:49:31 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point   a(0.0f, 0.0f);
    Point   b(5.0f, 0.0f);
    Point   c(0.0f, 5.0f);

    Point p1(3.0f, 1.0f);
    Point p2(0.0f, 0.0f);
    Point p3(5.0f, 0.0f);
    Point p4(10.0f, 10.f);

    Point points[] = {p1, p2, p3, p4};
    std::string labels[] = {"Point 1 (inside)", "Point 2 (vertex)", "Point 3 (edge)", "Point 4 (outside)"};
    for(int i = 0; i < 4; i++)
    {
        std::cout << labels[i] << " is ";
        if (bsp(a, b, c, points[i]))
            std::cout << "inside";
        else
            std::cout << "outside";
        std::cout << " the triangle." << std::endl;
    }
    return 0;
}