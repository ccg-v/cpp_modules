void ScalarConverter::displayConversions(const std::string &literal) {
	
    eType type = detectType(literal);
	
    switch (type) {
		
        case CHAR:
			std::cout << "Char type" << std::endl;
            try {
                char value = toChar(literal);
                std::cout << "char:\t'" << value << "'" << std::endl;
                std::cout << "int:\t" << static_cast<int>(value) << std::endl;
                std::cout << "float:\t" << std::fixed << std::setprecision(1)
						  << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "THIS NEVER APPEARS char: " << e.what() << std::endl;
            }
            break;

		case INT:
			std::cout << "Integer type" << std::endl;
			try {
				int value = toInteger(literal);

				//	Handle char conversion in its own try-catch block to throw exceptions
				try {
					if (value >= 32 && value <= 126) {
						std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
					} else if (value > 127 || value < 0) {
						throw OutOfRangeException(); // This will be caught by the outer block
					} else {
						throw NonDisplayableException(); // This will be caught by the inner block
					}
				} catch (const NonDisplayableException &e) {
					std::cout << "char:\t" << e.what() << std::endl;
				}

				// Proceed with the remaining conversions
				std::cout << "int:\t" << value << std::endl;
				std::cout << "float:\t" << std::fixed << std::setprecision(1)
						<< static_cast<float>(value) << "f" << std::endl;
				std::cout << "double:\t" << static_cast<double>(value) << std::endl;

			} catch (const OutOfRangeException &e) {
				// If 'OutOfRangeException' is thrown, we catch it here
				std::cout << "char:\t" << e.what() << std::endl;

				// The char conversion failed, but we still want to show float and double conversions
				std::cout << "int:\t" << toInteger(literal) << std::endl;
				std::cout << "float:\t" << std::fixed << std::setprecision(1)
						<< static_cast<float>(toInteger(literal)) << "f" << std::endl;
				std::cout << "double:\t" << static_cast<double>(toInteger(literal)) << std::endl;
			} catch (const std::exception &e) { 
				std::cout << "int:\t" << e.what() << std::endl;
			}
			break;

		case FLOAT:
			std::cout << "Float type" << std::endl;
			try {
				float value = toFloat(literal);
				
				// Handle char conversion
				if (value >= 0 && value <= 127) {
					if (value >= 32 && value <= 126) {
						std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
					} else {
						// std::cout << "char: Non displayable" << std::endl;
						throw NonDisplayableException();
					}
				} else {
					std::cout << "char: impossible" << std::endl;
				}

				// // Handle int conversion
				// if (value > static_cast<float>(std::numeric_limits<int>::max()) || 
				// 	value < static_cast<float>(std::numeric_limits<int>::min()) || 
				// 	std::isnan(value)) {
				// 	std::cout << "int: impossible" << std::endl;
				// } else {
				// 	std::cout << "int: " << static_cast<int>(value) << std::endl;
				// }
				try {
					if (toInteger(literal))
						std::cout << "HERE:\t" << toInteger(literal) << std::endl;
				} catch (const ImpossibleConversionException & e) {
					std::cout << "int:\t" << e.what() << std::endl;
				}

				// Display float
				std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
			} catch (const OutOfRangeException &) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: out of range" << std::endl;
			}

			// Always attempt to convert to double, even if float conversion failed
			try {
				// Remove 'f' suffix for double conversion
				std::string doubleStr = literal.substr(0, literal.length() - 1);
				double d_value = std::strtod(doubleStr.c_str(), NULL);
				if (d_value == HUGE_VAL || d_value == -HUGE_VAL) {
					throw OutOfRangeException();
				}
				std::cout << "double: " << std::fixed << std::setprecision(1) << d_value << std::endl;
			} catch (const OutOfRangeException &) {
				std::cout << "double: out of range" << std::endl;
			}
			break;

		case DOUBLE:
			std::cout << "Double type" << std::endl;
			try {
				double value = toDouble(literal);
				
				// // Handle char conversion
				// std::cout << "char: impossible" << std::endl;
						// Handle char conversion
				if (value >= 0 && value <= 127) {
					if (value >= 32 && value <= 126) {
						std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
					} else {
						std::cout << "char: Non displayable" << std::endl;
					}
				} else {
					std::cout << "char: impossible" << std::endl;
				}

				// Handle int conversion
				std::cout << "int: impossible" << std::endl;

				// Handle float conversion
				if (std::isnan(value) || std::isinf(value)) {
					std::cout << "float: " << (std::isnan(value) ? "nanf" : (value > 0 ? "+inff" : "-inff")) << std::endl;
				} else {
					float f_value = static_cast<float>(value);
					if (f_value != value) {
						std::cout << "float: impossible" << std::endl;
					} else {
						std::cout << "float: " << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
					}
				}

				// Display double
				if (std::isnan(value)) {
					std::cout << "double: nan" << std::endl;
				} else if (std::isinf(value)) {
					std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
				} else {
					std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
				}
			} catch (const OutOfRangeException &) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: out of range" << std::endl;
			}
			break;

			case UNKNOWN:
				std::cout << "Unknown type" << std::endl;
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break;
			default:
				std::cout << "Error: Unhandled type" << std::endl;
		// 		break;
    }
}