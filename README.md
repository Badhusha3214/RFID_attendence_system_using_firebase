<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>RFID / NFC Attendance System using Firebase</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      line-height: 1.6;
      max-width: 800px;
      margin: 0 auto;
      padding: 20px;
    }
    h1, h2, h3 {
      color: #333;
    }
    code {
      background-color: #f4f4f4;
      padding: 5px;
      border-radius: 4px;
    }
  </style>
</head>
<body>
  <h1>RFID / NFC Attendance System using Firebase</h1>
  <p>This project utilizes an ESP32 development board along with the RC522 RFID/NFC module to create an attendance system. The attendance data is managed and stored in a Firebase database. This README provides a comprehensive guide to set up and use the system effectively.</p>

  <h2>Components Used</h2>
  <ul>
    <li>ESP32 development board</li>
    <li>RC522 RFID/NFC module</li>
    <li>Jumper wires</li>
    <li>Breadboard</li>
    <li>Access to a Firebase account</li>
  </ul>

  <h2>Pin Connections</h2>
  <ul>
    <li><strong>RST</strong>: Pin 5</li>
    <li><strong>MISO</strong>: Pin 19</li>
    <li><strong>MOSI</strong>: Pin 23</li>
    <li><strong>SCK</strong>: Pin 18</li>
    <li><strong>SDA/SS</strong>: Pin 21</li>
  </ul>

  <h2>Setup Instructions</h2>
  <ol>
    <li>Connect the RC522 module to the ESP32 according to the pin connections provided above.</li>
    <li>Install the necessary libraries for the ESP32 and RC522 module.</li>
    <li>Set up a Firebase account and create a new project.</li>
    <li>Install the Firebase ESP32 library and configure it with your Firebase project credentials.</li>
    <li>Upload the provided Arduino code to your ESP32 board.</li>
    <li>Ensure that your ESP32 is connected to a stable Wi-Fi network.</li>
  </ol>

  <h2>Usage</h2>
  <ul>
    <li>When an RFID/NFC card is scanned, the system checks the Firebase database to see if the card UID is already recorded.</li>
    <li>If the card UID is not in the database, it adds a new attendance record for that UID.</li>
    <li>If the card UID is already recorded, the system removes one of the attendance records associated with that UID.</li>
  </ul>

  <h2>Considerations</h2>
  <ul>
    <li>Ensure that the power supply to the system is stable and provides sufficient current to both the ESP32 and RC522 module.</li>
    <li>Check for any electromagnetic interference that may affect the RFID/NFC module's performance.</li>
    <li>Regularly monitor the Firebase database for attendance records and manage them as needed.</li>
  </ul>

  <h2>Future Enhancements</h2>
  <ul>
    <li>Implement a web or mobile interface to view and manage attendance records.</li>
    <li>Add functionality to track attendance trends and generate reports.</li>
    <li>Enhance security features to prevent unauthorized access to the system.</li>
  </ul>

  <h2>Troubleshooting</h2>
  <ul>
    <li>If the system restarts when an RFID/NFC card is read, check the power supply and connections for stability.</li>
    <li>Ensure that the Firebase ESP32 library is correctly configured with your Firebase project credentials.</li>
    <li>Double-check the pin connections between the ESP32 and RC522 module.</li>
  </ul>

  <h2>Conclusion</h2>
  <p>The RFID/NFC attendance system using Firebase provides an efficient and reliable way to track attendance records. With proper setup and maintenance, it can streamline attendance management processes in various settings.</p>
  <p>Feel free to contribute to this project and tailor it to your specific requirements!</p>
</body>
</html>
