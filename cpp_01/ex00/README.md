<h1>Exercise 00: BraiiiiiiinnnzzzZ</h1>

<h2>Target</h2>
<p>Demonstrate the key concepts of dynamic memory allocation (heap) and stack allocation for creating and using zombie objects.</p>

<h2>Subject</h2>
<ol>
  <li>
    <p>Implement a Zombie class that holds the zombie's name and a function to announce himself</p>
    <pre><code>void announce( void );</code></pre>
  </li>
  <li>
    <p>Create two zombies using a different function for each:</p>
    <pre><code>Zombie *newZombie( std::string name);</code></pre>
	<pre><code>void randomChump( std::string name );</code></pre>
  </li>
</ol>

<p>The point of the exercise is to determine in what case it's better to allocate the zombies on the stack or heap</p>

<details>
  <summary>Click here for hint</summary>
<p></p> 
<p><i>The exercise aims to demonstrate the difference between allocating objects on the stack and on the heap in C++. When creating a Zombie object using the newZombie() function, a pointer to the Zombie is returned, allowing it to be accessed outside the function scope. Thus, it's allocated on the heap using dynamic memory allocation.</i></p>

<p><i>On the other hand, when creating a Zombie object with the randomChump() function, it's used solely within the function and isn't needed outside of it. Therefore, it's allocated on the stack, utilizing automatic memory allocation.</i></p>
  
</details>
