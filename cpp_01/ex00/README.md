<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Hidden Section Example</title>
<style>
  /* Hide the spoiler content by default */
  .spoiler-content {
    display: none;
  }
  
  /* Style for the spoiler checkbox */
  .spoiler-checkbox {
    display: none;
  }
  
  /* Style for the spoiler label */
  .spoiler-label {
    cursor: pointer;
    color: blue;
    text-decoration: underline;
  }
  
  /* Style for the spoiler content when revealed */
  .spoiler-checkbox:checked + .spoiler-label + .spoiler-content {
    display: block;
  }
</style>
</head>
<body>

<h1>Hidden Section Example</h1>

<!-- Checkbox to toggle the visibility of the spoiler content -->
<input type="checkbox" id="spoiler-checkbox" class="spoiler-checkbox">
<label for="spoiler-checkbox" class="spoiler-label">Show Spoiler</label>

<!-- Hidden spoiler content -->
<div class="spoiler-content">
  <h2>Spoiler Alert!</h2>
  <p>This is the hidden content that the user can reveal by clicking the label.</p>
</div>

</body>
</html>
