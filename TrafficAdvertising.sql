USE TrafficAdvertising;

CREATE TABLE TrafficCount(
ID INT PRIMARY KEY IDENTITY(1,1),
SensorID INT FOREIGN KEY REFERENCES Sensors(ID),
LocationID INT FOREIGN KEY REFERENCES Locations(ID),
RegisterDate DATETIME
);

CREATE TABLE Sensors(
ID INT PRIMARY KEY IDENTITY(1,1),
SensorName VARCHAR(255)
);

CREATE TABLE Locations(
ID INT PRIMARY KEY IDENTITY(1,1),
Street VARCHAR(255),
City VARCHAR(255),
Country VARCHAR(255)
);

INSERT INTO Sensors(SensorName)
VALUES ('HC-SR501 PIR Motion Sensor Module');


INSERT INTO Sensors(SensorName)
VALUES ('HC-SR04 Ultrasonic Ranging Module');


INSERT INTO Locations(Street, City, Country)
VALUES ('S Miami Avenue', 'Miami', 'USA');


INSERT INTO Locations(Street, City, Country)
VALUES ('W Flager St', 'Miami', 'USA');

INSERT INTO TrafficCount(LocationID, SensorID, RegisterDate)
VALUES (1, 1, '2022-06-21 17:14:34');

INSERT INTO TrafficCount(LocationID, SensorID, RegisterDate)
VALUES (2, 2, '2022-06-22 22:00:00');


SELECT * FROM Sensors;
SELECT * FROM Locations;
SELECT * FROM TrafficCount;

SELECT COUNT(RegisterDate)
FROM TrafficCount
WHERE RegisterDate >= '2022-06-22' AND  RegisterDate <= '2022-06-23' AND LocationID = 2; 

SELECT* FROM   
TrafficCount WHERE cast (datediff (day, '2022-06-22', '2022-06-23') as datetime) = '2022-06-22';

SELECT COUNT(RegisterDate) 
FROM TrafficCount
WHERE CONVERT(VARCHAR(25), RegisterDate, 126) LIKE '2022-06-22%' AND LocationID = 2;

DELETE FROM TrafficCount
WHERE RegisterDate >= '2022-06-29';
