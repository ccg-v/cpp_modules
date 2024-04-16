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
