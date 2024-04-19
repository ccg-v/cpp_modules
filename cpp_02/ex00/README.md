<h1>Exercise 00: My First Class in Orthodox Canonical Form</h1>

<h2>Target</h2>
<p>Learn about the Orthodox Canonical Form for classes, and the fixed-point numbers,/p>

<h2>Subject</h2>
<p>Create a class in Orthodox Canonical Form that represents a fixed-point number:</p>

<ol><li>
  <p>Private members:</p>
</li></ol>
  <li>
    <p>		An integer to store the fixed-point number value.</p>
    <p>		A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.</p>
  </li>
<li>
  <p>Public members:</p>
</li>
  <li>
     <p>A default constructor that initializes the fixed-point number value to 0.</p>
     <p>A copy constructor.</p>
     <p>A copy assignment operator overload.</p>
     <p>A destructor</p>
     <p>A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.</p>
     <p>A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number.</p>
  </li>
