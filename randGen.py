import random
listWords = ["Hyderabad", "Amritsar", "Guwahati", "Bhubaneswar", "Gaya", "New Delhi", "Port Blair", "Ahmedabad", "Bengaluru", "Mangalore", "Kochi", "Kozhikode", "Thiruvananthapuram", "Mumbai", "Nagpur", "Jaipur", "Chennai",
             "Tiruchirappalli", "Lucknow", "Varanasi", "Kolkata", "Kanpur", "Surat", "Indore", "Dabolim", "Coimbatore", "Srinagar", "Imphal", "Madurai", "Siliguri", "Mangalore", "Chandigarh", "Nashik", "Vadodara", "Kushinagar"]
listFareAdult = [4000, 4500, 5000, 5500]
listFareChild = [3000, 3500, 2000, 2500]
listFareInfant = [1000, 1500, 2000, 2500]
for i in range(50):
    print(random.randint(10001, 99999), end=' ')
    print(f"Des:{random.choice(listWords)}", end=' ')
    print(f"Ori:{random.choice(listWords)}", end=' ')
    print(random.randint(0, 24), end='')
    print(random.randint(0, 59), end='')
    print(" ", end='')
    print(random.randint(100, 200), end=' ')
    print(random.randint(1, 30), end='/')
    print(random.randint(1, 12), end='/')
    print(random.randint(2020, 2022), end=' ')
    print(random.choice(listFareAdult), end=' ')
    print(random.choice(listFareChild), end=' ')
    print(random.choice(listFareInfant), end='\n')
