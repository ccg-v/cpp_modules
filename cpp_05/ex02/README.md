# Exercise 02: No, you need form 28B, not 28C...

In this exercise, the abstract base class (AForm) ensures that all forms (ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm) implement the execute method. This provides a clear contract that any concrete form must follow, thus enabling polymorphism and ensuring consistency in how forms are handled.

The subject requires to add a 
```execute(Bureaucrat const & executor) const``` 
member function to the base form and implement a function to execute the form’s action of the concrete classes. **By adding this function as pure virtual we will make the Form class abstract.**