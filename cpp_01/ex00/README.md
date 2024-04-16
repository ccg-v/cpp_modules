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

<p>The point of the exercise is to determine in what case it's better to allocate the zombies on the stack or heap</p>

<p>'*newZombie()' returns a pointer to the Zombie object. This means it can be used outside of the function scope, so it must be allocated on the heap. Instead, the instance of Zombie created in 'randomChump' cannot be used outside of the function, it must be allocated on the stack memory.</p>

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Hidden Section Example</title>
<style>
  /* Hide the spoiler section by default */
  #spoiler {
    display: none;
  }
</style>
</head>
<body>

<h1>Hidden Section Example</h1>

<!-- Button to toggle the visibility of the spoiler section -->
<button onclick="toggleSpoiler()">Show Spoiler</button>

<!-- Hidden spoiler section -->
<div id="spoiler">
  <h2>Spoiler Alert!</h2>
  <p>This is the hidden content that the user can reveal by clicking the button.</p>
</div>

<script>
  // JavaScript function to toggle the visibility of the spoiler section
  function toggleSpoiler() {
    var spoiler = document.getElementById("spoiler");
    if (spoiler.style.display === "none") {
      spoiler.style.display = "block";
    } else {
      spoiler.style.display = "none";
    }
  }
</script>

</body>
</html>
