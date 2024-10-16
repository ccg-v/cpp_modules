/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:15:37 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/16 18:14:09 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        // Create a custom error message
        std::ostringstream oss;
        oss << "Value '" << value << "': No occurrence found";
        throw std::runtime_error(oss.str());  // Throw the dynamically generated message		
		// throw NoOccurrenceFoundException();
    }
    return it;
}

// Specialization for C-style arrays
template <typename T, size_t N>
T* easyfind(T (&array)[N], int value) {
    T* it = std::find(array, array + N, value);
    if (it == array + N) {
        std::ostringstream oss;
        oss << "Value '" << value << "': No occurrence found";
        throw std::runtime_error(oss.str());
		// throw NoOccurrenceFoundException();
    }
    return it;
}

// Generic function to print container contents
template <typename T>
void printContainer(const T& container) {
    std::cout << "{ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;
}

// Specialization for C-style arrays
template <typename T, size_t N>
void printContainer(T (&array)[N]) {
    std::cout << "{ ";
    for (size_t i = 0; i < N; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "}" << std::endl;
}

// // Exception
// const char* NoOccurrenceFoundException::what() const throw() {
// 	return "No occurrence found";
// }
