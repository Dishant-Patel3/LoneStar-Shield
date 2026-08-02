# SafeZone - Texas Sex Offender Registry Map

## What Is This?

SafeZone is an interactive map that shows you where registered sex offenders live in Texas. It's designed to help you stay informed about your neighborhood and make safer decisions about where you are.

## Why We Built This

Understanding your surroundings is key to keeping yourself and your loved ones safe. This tool makes it easy to visualize offender locations across Texas in a simple, user-friendly way.

---

## How to Use the App

### Opening the App
1. Simply open the web application any web browser (Chrome, Firefox, Safari, etc.)
2. The map will load showing Texas with all registered sex offender locations

### Searching for Your Location
1. **Type your location** in the search box at the top left
   - You can enter a ZIP code (e.g., `78701`)
   - Or enter a city name (e.g., `Austin`, `Houston`, `Dallas`)
2. **Click the search button** or press `Enter`
3. The map will automatically zoom to your location

### Exploring the Map
- **Zoom in/out**: Use your mouse wheel or the `+` and `-` buttons on the map
- **Pan around**: Click and drag the map to move around
- **Click clusters**: The colored circles show groups of offenders - click them to zoom in closer
- **View individual offenders**: Click on blue pins to see offender ID and name

---

## Understanding the Map Colors

The map uses colored circles (clusters) to show how many offenders are in an area:

🟢 **Green Circle (2-10 offenders)**
- Safer area with few registered offenders

🟡 **Yellow Circle (11-100 offenders)**  
- Moderate number of offenders in the area

🟠 **Orange Circle (101-500 offenders)**
- Higher concentration of offenders

🔴 **Red Circle (500+ offenders)**
- Very high concentration of offenders

📍 **Blue Pin**
- This marks the exact location of an individual registered sex offender
- Click on it to see their ID and name

### What Do the Numbers Mean?

The number inside each colored circle tells you **exactly how many offenders** are grouped in that area. For example, a yellow circle with "45" means there are 45 registered offenders in that zone.

---

## Tips for Using SafeZone

**Click on clusters** - When you see a colored circle, click it! The map will zoom in and break it into smaller clusters or individual pins.

**Zoom in for details** - The closer you zoom, the more specific information you'll see about individual locations.

**No location needed** - You don't have to use the search box! Feel free to explore the map freely by zooming and panning.

---

## Important Things to Know

**Texas Only** - This map only shows registered sex offenders in the state of Texas.

**Data Accuracy** - The data is based on official registry information, but may not be 100% up-to-date in real-time.

**Privacy & Safety** - This information is public record, but please use it responsibly.

**Stay Aware** - While this tool is helpful, always practice general safety awareness in your daily life.

---

## How app is built:

- **Leaflet.js** - An open-source mapping library
- **MarkerCluster** - Groups nearby markers into colored clusters
- **C++ Backend** - Processes offender data from files from the official Texas database
- **Nominatim API** - Geocodes your search queries (converts ZIP codes/cities to map coordinates)

