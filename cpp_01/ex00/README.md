# cpp 01 - ex00
TARGET: Demonstrate the key concepts of dynamic memory allocation (heap) and
stack allocation for creating and using zombie objects.

SUBJECT:
 	1. Implement a Zombie class that holds the zombie's name and a function
		to announce himself
			void announce( void ); 
	2. Create two zombies using a different function for each:
			Zombie *newZombie( std::string name);
			void randomChump( std::string name );

'*newZombie()' returns a pointer to the Zombie object. This means it can be
used outside of the function scope, so it must be allocated on the heap. 
Instead, the instance of Zombie created in 'randomChump' cannot be used 
outside of the function, it must be allocated on the stack memory.

<h1>cpp 01 - ex00</h1>

<h2>TARGET</h2>
<p>Demonstrate the key concepts of dynamic memory allocation (heap) and stack allocation for creating and using zombie objects.</p>

<h2>SUBJECT</h2>
<ol>
  <li>
    <p>Implement a Zombie class that holds the zombie's name and a function to announce himself</p>
    <pre><code>void announce( void );</code></pre>
  </li>
  <li>
    <p>Create two zombies using a different function for each:</p>
    <pre><code>Zombie *newZombie( std::string name);<br>void randomChump( std::string name );</code></pre>
  </li>
</ol>

<p>'*newZombie()' returns a pointer to the Zombie object. This means it can be used outside of the function scope, so it must be allocated on the heap. Instead, the instance of Zombie created in 'randomChump' cannot be used outside of the function, it must be allocated on the stack memory.</p>
