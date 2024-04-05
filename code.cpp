#include <iostream>     // Standard input/output stream library
#include <vector>       // Vector container library
#include <random>       // Random number generation library
#include <sstream>      // String stream processing library
#include <string>       // String library
#include <chrono>       // Time library for time-related functions
#include <ctime>        // C-style time library for time manipulation
#include <iomanip>      // Input/output manipulator library for formatting

using namespace std;    // Standard namespace for C++ standard library

// Forward declarations of blockchain structs
struct SupplierBlockchain; // Supply
struct PressBlockchain; // Press
struct WeldingBlockchain; // Welding
struct PaintingBlockchain; // Painting
struct AssemblyBlockchain; // Assembly
struct ShippingBlockchain; // Shipping
struct TransactionBlockchain; // Transaction

// Global variables
int blockNumber = 1;                    // Variable to track the block number
const string ANSI_GREEN = "\033[1;32m"; // ANSI escape code for green color
const string ANSI_RESET = "\033[0m";    // ANSI escape code to reset color
const string ANSI_BLUE = "\033[1;34m";  // ANSI escape code for blue color
const string ANSI_RED = "\033[1;31m";   // ANSI escape code for red color

// Dataset containing information about various stages of car manufacturing
vector<vector<string>> dataset = {
    // Supplier data: Supplier ID, Supplier Name, Product, Address, Branch, Quantity, Price
    {"SUP001", "ABC Suppliers", "Product X", "123 Main Street", "Branch A", "100", "50.75"},

    // Press data: Press ID, Location, Details, Type, Manufacturer
    {"PRS001", "456 Industrial Avenue", "Heavy-duty press machine", "Hydraulic", "XYZ Machinery Inc."},

    // Welding data: Welding ID, Location, Details, Type, Material, Temperature
    {"WLD002", "789 Industrial Avenue", "Robotic welding station", "MIG", "Steel", "2200.0"},

    // Painting data: Painting ID, Location, Details, Color, Type, Thickness
    {"PNT003", "123 Main Street", "Automated painting booth", "Red", "Acrylic", "0.02"},

    // Assembly data: Assembly ID, Location, Details, Type, Number of Parts, Weight
    {"ASM004", "456 Elm Street", "Automated assembly line", "Car", "150", "1200.5"},

    // Shipping data: Shipping ID, Destination, Details, Type, Carrier Name, Status
    {"SHIP005", "New York", "Shipment of car parts", "Air", "ABC Airlines", "In transit"},

    // Transaction data: Transaction ID, Type, Sender, Receiver, Currency, Amount, Status
    {"TRANS007", "Purchase", "Company A", "Company B", "USD", "1500.75", "Completed"},
};

// Initialize the random number generator with the current time point including milliseconds
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

//Function prototypes
// Function to generate a blockchain block for the supplier stage
SupplierBlockchain generateSupplierBlockChain(string supplierId, string supplierName, string supplierItem, string location, string branch, string quantity, string price);
// Function to generate a blockchain block for the press stage
PressBlockchain generatePressBlockChain(string pressId, string pressLocation, string pressDetails, string pressType, string pressManufacturer, string pressCapacity, SupplierBlockchain *ptr);
// Function to generate a blockchain block for the welding stage
WeldingBlockchain generateWeldingBlockChain(string weldingId, string weldingLocation, string weldingDetails, string weldingType, string weldingMaterial, string weldingTemperature, PressBlockchain *ptr);
// Function to generate a blockchain block for the painting stage
PaintingBlockchain generatePaintingBlockChain(string paintingId, string paintingLocation, string paintingDetails, string PaintingColor, string paintingType, string paintingThickness, WeldingBlockchain *ptr);
// Function to generate a blockchain block for the assembly stage
AssemblyBlockchain generateAssemblyBlockChain(string assemblyId, string assemblyLocation, string assemblyDetails, string assemblyType, string numberOfParts, string assemblyWeight, PaintingBlockchain *ptr);
// Function to generate a blockchain block for the shipping stage
ShippingBlockchain generateShippingBlockChain(string shippingId, string shippingDestination, string shippingDetails, string shippingType, string carrierName, string shippingStatus, AssemblyBlockchain *ptr);
// Function to generate a blockchain block for the transaction stage
TransactionBlockchain generateTransactionBlockChain(string transactionId, string transactionType, string transactionAmount, string sender, string receiver, string currency, string transactionStatus, ShippingBlockchain *ptr);
// Function to print the dataset
void printDataset(const vector<vector<string>>& dataset);
// Function to print a block in the SupplierBlockchain
void printSupplierBlockchain(const SupplierBlockchain& block);
// Function to print a block in the PressBlockchain
void printPressBlockchain(const PressBlockchain& block);
// Function to print a block in the WeldingBlockchain
void printWeldingBlockchain(const WeldingBlockchain& block);
// Function to print a block in the PaintingBlockchain
void printPaintingBlockchain(const PaintingBlockchain& block);
// Function to print a block in the AssemblyBlockchain
void printAssemblyBlockchain(const AssemblyBlockchain& block);
// Function to print a block in the ShippingBlockchain
void printShippingBlockchain(const ShippingBlockchain& block);
// Function to print a block in the TransactionBlockchain
void printTransactionBlockchain(const TransactionBlockchain& block);
// Function to generate a hash for a blockchain block
string generateBlockHash();
// Function to generate a timestamp for a blockchain block
string generateTimestamp();


//Structures
struct User { // Define a struct to hold user credentials
    string username; // username
    string password; // password
};

struct SupplierBlockchain {
    int blockNumber;             // Unique number or identifier of the block
    string currentBlockHash;     // Hash value of the current block's data
    string previousBlockHash;    // Hash value of the previous block's data
    string timestamp;            // Timestamp indicating when the block was created
    string supplierId;           // Identifier of the supplier associated with this block
    string supplierName;         // Name of the supplier associated with this block
    string supplierItem;         // Item provided by the supplier
    string location;             // Location of the supplier
    string branch;               // Branch of the supplier
    string quantity;             // Quantity of the supplied item
    string price;                // Price of the supplied item
    PressBlockchain *ptr;        // Pointer to the next stage (PressBlockchain) in the blockchain
};


struct PressBlockchain {
    int blockNumber;             // Unique number or identifier of the block
    string currentBlockHash;     // Hash value of the current block's data
    string previousBlockHash;    // Hash value of the previous block's data
    string timestamp;            // Timestamp indicating when the block was created
    string pressId;              // Identifier of the press associated with this block
    string pressLocation;        // Location of the press
    string pressDetails;         // Details or description of the press
    string pressType;            // Type of the press (e.g., hydraulic, pneumatic)
    string pressManufacturer;    // Manufacturer of the press
    string pressCapacity;        // Capacity of the press (e.g., in tons)
    WeldingBlockchain *ptr;      // Pointer to the next stage (WeldingBlockchain) in the blockchain
};


struct WeldingBlockchain {
    int blockNumber;             // Unique number or identifier of the block
    string currentBlockHash;     // Hash value of the current block's data
    string previousBlockHash;    // Hash value of the previous block's data
    string timestamp;            // Timestamp indicating when the block was created
    string weldingId;            // Identifier of the welding process associated with this block
    string weldingLocation;      // Location where welding took place
    string weldingDetails;       // Details or description of the welding process
    string weldingType;          // Type of welding process (e.g., MIG, TIG)
    string weldingMaterial;      // Material being welded
    string weldingTemperature;   // Temperature of the welding process
    PaintingBlockchain *ptr;     // Pointer to the next stage (PaintingBlockchain) in the blockchain
};

struct PaintingBlockchain {
    int blockNumber;             // Unique number or identifier of the block
    string currentBlockHash;     // Hash value of the current block's data
    string previousBlockHash;    // Hash value of the previous block's data
    string timestamp;            // Timestamp indicating when the block was created
    string paintingId;          // Identifier of the painting process associated with this block
    string paintingLocation;    // Location where painting took place
    string paintingDetails;     // Details or description of the painting process
    string paintingColor;       // Color of the paint used
    string paintingType;        // Type or method of painting (e.g., spray painting)
    string paintingThickness;   // Thickness of the paint layer applied
    AssemblyBlockchain *ptr;    // Pointer to the next stage (AssemblyBlockchain) in the blockchain
};


struct AssemblyBlockchain {
    int blockNumber;             // Unique number or identifier of the block
    string currentBlockHash;     // Hash value of the current block's data
    string previousBlockHash;    // Hash value of the previous block's data
    string timestamp;            // Timestamp indicating when the block was created
    string assemblyId;          // Identifier of the assembly process associated with this block
    string assemblyLocation;    // Location where assembly took place
    string assemblyDetails;     // Details or description of the assembly process
    string assemblyType;        // Type or category of assembly (e.g., vehicle assembly)
    string numberOfParts;       // Number of parts used in the assembly
    string assemblyWeight;      // Weight of the assembled product
    ShippingBlockchain *ptr;    // Pointer to the next stage (ShippingBlockchain) in the blockchain
};


struct ShippingBlockchain {
    int blockNumber;                // Unique number or identifier of the block
    string currentBlockHash;        // Hash value of the current block's data
    string previousBlockHash;       // Hash value of the previous block's data
    string timestamp;               // Timestamp indicating when the block was created
    string shippingId;             // Identifier of the shipping process associated with this block
    string shippingDestination;    // Destination of the shipment
    string shippingDetails;        // Details or description of the items being shipped
    string shippingType;           // Type or mode of shipping (e.g., air, sea, land)
    string carrierName;            // Name of the shipping carrier or company
    string shippingStatus;         // Current status of the shipping process
    TransactionBlockchain *ptr;    // Pointer to the next stage (TransactionBlockchain) in the blockchain
};


struct TransactionBlockchain {
    int blockNumber;            // Unique number or identifier of the block
    string currentBlockHash;    // Hash value of the current block's data
    string previousBlockHash;   // Hash value of the previous block's data
    string timestamp;           // Timestamp indicating when the block was created
    string transactionId;       // Identifier of the transaction
    string transactionType;     // Type or category of the transaction
    string sender;              // Sender of the transaction
    string receiver;            // Receiver of the transaction
    string currency;            // Currency used in the transaction
    string transactionAmount;   // Amount involved in the transaction
    string transactionStatus;   // Current status of the transaction
};


//Functions
// Function to perform user authentication
bool authenticateUser(const std::string& inputUsername, const std::string& inputPassword, const User& validUser) {
    // Check if the input credentials match the valid user's credentials
    return (inputUsername == validUser.username && inputPassword == validUser.password);
}

void printDataset(const vector<vector<string>>& dataset){
    cout << "\n===== Dataset =====\n" << endl;
    cout << ANSI_RED;
    for (const auto& row : dataset) {
        for (const auto& element : row) {
            cout << element << " | "; // Print each element followed by a separator
        }
        cout << endl; // Add newline after each row
    }
    cout << "\n" << endl;
    cout << ANSI_RESET;

}

// Function to print a SupplierBlockchain block
void printSupplierBlockchain(const SupplierBlockchain& block) {
    cout << "\n===== Stage 1 : Supply =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Supplier ID    : " << block.supplierId << endl;
    cout << "Supplier Name  : " << block.supplierName << endl;
    cout << "Supplier Item  : " << block.supplierItem << endl;
    cout << "Location       : " << block.location << endl;
    cout << "Branch         : " << block.branch << endl;
    cout << "Quantity       : " << block.quantity << endl;
    cout << "Price          : " << block.price << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Supply Stage Overview]    : Initial phase of car manufacturing, sourcing raw materials and components." << endl;
    cout << "2. [Key Activities]           : Identifying reliable suppliers, negotiating contracts, monitoring inventory." << endl;
    cout << "3. [Materials and Components] : Metals, plastics, rubber, glass, electronics, and specialized parts." << endl;
    cout << "4. [Quality Control]          : Ensuring received materials meet standards through inspections." << endl;
    cout << "5. [Supply Chain Management]  : Efficient management practices to minimize delays and optimize production." << endl;
    cout << "6. [Supplier Relationships]   : Building strong relationships for reliable and sustainable supply chains." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a PressBlockchain block
void printPressBlockchain(const PressBlockchain& block) {
    cout << "===== Stage 2 : Press =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Press ID            : " << block.pressId << endl;
    cout << "Press Location      : " << block.pressLocation << endl;
    cout << "Press Details       : " << block.pressDetails << endl;
    cout << "Press Type          : " << block.pressType << endl;
    cout << "Press Manufacturer  : " << block.pressManufacturer << endl;
    cout << "Press Capacity      : " << block.pressCapacity << " tons" << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Press Stage Overview]         : Shaping metal components using hydraulic or mechanical presses." << endl;
    cout << "2. [Press Types]                  : Hydraulic press, mechanical press, stamping press, forging press." << endl;
    cout << "3. [Press Capacity]               : Indicates the maximum force exerted by the press, measured in tons." << endl;
    cout << "4. [Press Manufacturer]           : Company responsible for designing, manufacturing, and supplying the press." << endl;
    cout << "5. [Quality Assurance]            : Ensuring precise and consistent shaping of metal parts for assembly." << endl;
    cout << "6. [Efficiency and Productivity]  : Optimization of press operations for higher output and reduced cycle times." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a WeldingBlockchain block
void printWeldingBlockchain(const WeldingBlockchain& block) {
    cout << "===== Stage 3 : Welding =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Welding ID           : " << block.weldingId << endl;
    cout << "Welding Location     : " << block.weldingLocation << endl;
    cout << "Welding Details      : " << block.weldingDetails << endl;
    cout << "Welding Type         : " << block.weldingType << endl;
    cout << "Welding Material     : " << block.weldingMaterial << endl;
    cout << "Welding Temperature  : " << block.weldingTemperature << " Celsius" << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Welding Stage Overview]   : Joining metal components using various welding techniques and materials." << endl;
    cout << "2. [Welding Types]            : MIG (Metal Inert Gas), TIG (Tungsten Inert Gas), Arc welding, Spot welding." << endl;
    cout << "3. [Welding Materials]        : Metals, alloys, plastics, composites." << endl;
    cout << "4. [Welding Temperature]      : Temperature at which the welding process occurs, measured in Celsius." << endl;
    cout << "5. [Quality Assurance]        : Ensuring structural integrity and proper bonding of welded components." << endl;
    cout << "6. [Efficiency and Precision] : Optimization of welding parameters for consistent and high-quality welds." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a PaintingBlockchain block
void printPaintingBlockchain(const PaintingBlockchain& block) {
    cout << "===== Stage 4 : Paint =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << ANSI_RESET;
    cout << "Painting ID          : " << block.paintingId << endl;
    cout << "Painting Location    : " << block.paintingLocation << endl;
    cout << "Painting Details     : " << block.paintingDetails << endl;
    cout << "Painting Color       : " << block.paintingColor << endl;
    cout << "Painting Type        : " << block.paintingType << endl;
    cout << "Painting Thickness   : " << block.paintingThickness << " mm" << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Painting Stage Overview]      : Applying protective and decorative coatings to car bodies." << endl;
    cout << "2. [Painting Process]             : Surface preparation, primer application, base coat, clear coat." << endl;
    cout << "3. [Painting Color]               : Choice of colors for aesthetics and brand identity." << endl;
    cout << "4. [Painting Type]                : Solid, metallic, pearlescent, matte, gloss." << endl;
    cout << "5. [Painting Thickness]           : Thickness of the paint layer applied, measured in millimeters." << endl;
    cout << "6. [Quality Assurance]            : Ensuring uniformity, adhesion, and durability of the paint finish." << endl;
    cout << "7. [Environmental Considerations] : Compliance with environmental regulations regarding paint application and waste disposal." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a AssemblyBlockchain block
void printAssemblyBlockchain(const AssemblyBlockchain& block) {
    cout << "===== Stage 5 : Assembly =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Assembly ID        : " << block.assemblyId << endl;
    cout << "Assembly Location  : " << block.assemblyLocation << endl;
    cout << "Assembly Details   : " << block.assemblyDetails << endl;
    cout << "Assembly Type      : " << block.assemblyType << endl;
    cout << "Number of Parts    : " << block.numberOfParts << endl;
    cout << "Assembly Weight    : " << block.assemblyWeight << " kg" << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Assembly Stage Overview]  : Combining various components and subsystems to form complete vehicles." << endl;
    cout << "2. [Assembly Process]         : Sequential assembly line process, with each station performing specific tasks." << endl;
    cout << "3. [Assembly Type]            : Body assembly, chassis assembly, powertrain assembly, final assembly." << endl;
    cout << "4. [Number of Parts]          : Total number of components required to assemble a vehicle." << endl;
    cout << "5. [Assembly Weight]          : Total weight of the assembled vehicle, including all components." << endl;
    cout << "6. [Quality Assurance]        : Ensuring fit, finish, and functionality of assembled vehicles." << endl;
    cout << "7. [Testing]                  : Conducting final inspections and functional tests before vehicles are shipped." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a ShippingBlockchain block
void printShippingBlockchain(const ShippingBlockchain& block) {
    cout << "===== Stage 6 : Shipping =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Shipping ID            : " << block.shippingId << endl;
    cout << "Shipping Destination   : " << block.shippingDestination << endl;
    cout << "Shipping Details       : " << block.shippingDetails << endl;
    cout << "Shipping Type          : " << block.shippingType << endl;
    cout << "Carrier Name           : " << block.carrierName << endl;
    cout << "Shipping Status        : " << block.shippingStatus << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Shipping Stage Overview]  : Transporting assembled vehicles from manufacturing plants to distribution centers or dealerships." << endl;
    cout << "2. [Shipping Process]         : Coordinating logistics, loading vehicles onto carriers, and delivering them to their destinations." << endl;
    cout << "3. [Shipping Type]            : Different modes of transportation such as road, rail, sea, or air shipping." << endl;
    cout << "4. [Carrier Name]             : Name of the shipping company or carrier responsible for transporting vehicles." << endl;
    cout << "5. [Shipping Status]          : Tracking the status of shipments, including in transit, delivered, or awaiting delivery." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to print a TransactionBlockchain block
void printTransactionBlockchain(const TransactionBlockchain& block) {
    cout << "===== Stage 7 : Transaction =====\n" << endl;
    cout << ANSI_GREEN;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Block Number     |         Current Block Hash         |         Previous Block Hash         |     Timestamp     |" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|          " << block.blockNumber << "           |  " << block.currentBlockHash << "  |   " << block.previousBlockHash << "  | " <<block.timestamp << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << ANSI_RESET;

    cout << "Transaction ID      : " << block.transactionId << endl;
    cout << "Transaction Type    : " << block.transactionType << endl;
    cout << "Transaction Amount  : " << block.transactionAmount << endl;
    cout << "Sender              : " << block.sender << endl;
    cout << "Receiver            : " << block.receiver << endl;
    cout << "Currency            : " << block.currency << endl;
    cout << "Transaction Status  : " << block.transactionStatus << endl;
    cout << endl;

    cout << ANSI_BLUE;
    cout << "1. [Transaction Stage Overview] : Finalizing the purchase transaction for vehicles between entities involved, such as manufacturers, dealerships, or customers." << endl;
    cout << "2. Transaction Type]            : Types of transactions include purchases, sales, payments, or transfers of ownership." << endl;
    cout << "3. [Transaction Amount]         : Monetary value involved in the transaction, typically denoted in the specified currency." << endl;
    cout << "4. [Sender and Receiver]        : Identifying parties involved in the transaction, indicating the entity sending or receiving the payment or vehicle." << endl;
    cout << "5. [Currency]                   : The currency used for the transaction, such as USD (US Dollar), EUR (Euro), or any other applicable currency." << endl;
    cout << "6. [Transaction Status]         : Indicating the status of the transaction, whether it's completed, pending, or failed." << endl;
    cout << "\n" << endl;
    cout << ANSI_RESET;
}

// Function to generate a block hash using SHA-256 algorithm
string generateBlockHash() {
    // Define the characters that can be used in the hash
    const string charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Generate a hash of length 32 characters
    const int hashLength = 32;
    uniform_int_distribution<int> dist(0, charset.size() - 1);
    stringstream ss;
    for (int i = 0; i < hashLength; ++i) {
        ss << charset[dist(rng)]; // Append a random character from the charset to the hash
    }
    return ss.str(); // Return the generated hash
}

// Function to generate a timestamp in the format "YYYYMMDD:HH:MM:SS"
string generateTimestamp() {
    // Get the current time using the time function and convert it to a tm struct
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    // Format the timestamp as "YYYYMMDD:HH:MM:SS"
    ostringstream oss;
    oss << put_time(localTime, "%Y%m%d:%H:%M:%S");
    return oss.str();
}


// Function to generate a new SupplierBlockchain block
SupplierBlockchain generateSupplierBlockChain(string supplierId, string supplierName, string supplierItem, string location, string branch, string quantity, string price) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new SupplierBlockchain block
    SupplierBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = newBlockHash; // Assuming the first block's previous hash is also the current hash
    block.timestamp = newTimestamp;

    // Set the supplier-specific data
    block.supplierId = supplierId;
    block.supplierName = supplierName;
    block.supplierItem = supplierItem;
    block.location = location;
    block.branch = branch;
    block.quantity = quantity;
    block.price = price;

    // Return the created block
    return block;
}


// Function to generate a new PressBlockchain block
PressBlockchain generatePressBlockChain(string pressId, string pressLocation, string pressDetails, string pressType, string pressManufacturer, string pressCapacity, SupplierBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new PressBlockchain block
    PressBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the press-specific data
    block.pressId = pressId;
    block.pressLocation = pressLocation;
    block.pressDetails = pressDetails;
    block.pressType = pressType;
    block.pressManufacturer = pressManufacturer;
    block.pressCapacity = pressCapacity;

    // Return the created block
    return block;
}


// Function to generate a new WeldingBlockchain block
WeldingBlockchain generateWeldingBlockChain(string weldingId, string weldingLocation, string weldingDetails, string weldingType, string weldingMaterial, string weldingTemperature, PressBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new WeldingBlockchain block
    WeldingBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the welding-specific data
    block.weldingId = weldingId;
    block.weldingLocation = weldingLocation;
    block.weldingDetails = weldingDetails;
    block.weldingType = weldingType;
    block.weldingMaterial = weldingMaterial;
    block.weldingTemperature = weldingTemperature;

    // Return the created block
    return block;
}


// Function to generate a new PaintingBlockchain block
PaintingBlockchain generatePaintingBlockChain(string paintingId, string paintingLocation, string paintingDetails, string PaintingColor, string paintingType, string paintingThickness, WeldingBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new PaintingBlockchain block
    PaintingBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the painting-specific data
    block.paintingId = paintingId;
    block.paintingLocation = paintingLocation;
    block.paintingDetails = paintingDetails;
    block.paintingColor = PaintingColor; // Renamed variable to adhere to camelCase naming convention
    block.paintingType = paintingType;
    block.paintingThickness = paintingThickness;

    // Return the created block
    return block;
}


// Function to generate a new AssemblyBlockchain block
AssemblyBlockchain generateAssemblyBlockChain(string assemblyId, string assemblyLocation, string assemblyDetails, string assemblyType, string numberOfParts, string assemblyWeight, PaintingBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new AssemblyBlockchain block
    AssemblyBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the assembly-specific data
    block.assemblyId = assemblyId;
    block.assemblyLocation = assemblyLocation;
    block.assemblyDetails = assemblyDetails;
    block.assemblyType = assemblyType;
    block.numberOfParts = numberOfParts;
    block.assemblyWeight = assemblyWeight;

    // Return the created block
    return block;
}


// Function to generate a new ShippingBlockchain block
ShippingBlockchain generateShippingBlockChain(string shippingId, string shippingDestination, string shippingDetails, string shippingType, string carrierName, string shippingStatus, AssemblyBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new ShippingBlockchain block
    ShippingBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the shipping-specific data
    block.shippingId = shippingId;
    block.shippingDestination = shippingDestination;
    block.shippingDetails = shippingDetails;
    block.shippingType = shippingType;
    block.carrierName = carrierName;
    block.shippingStatus = shippingStatus;

    // Return the created block
    return block;
}


// Function to generate a new TransactionBlockchain block
TransactionBlockchain generateTransactionBlockChain(string transactionId, string transactionType, string transactionAmount, string sender, string receiver, string currency, string transactionStatus, ShippingBlockchain *ptr) {
    // Generate a new block hash and timestamp for the block
    string newBlockHash = generateBlockHash();
    string newTimestamp = generateTimestamp();

    // Create a new TransactionBlockchain block
    TransactionBlockchain block;

    // Set the block number (blockNumber is a global variable and increment it)
    block.blockNumber = blockNumber++;

    // Set the current block hash, previous block hash, and timestamp
    block.currentBlockHash = newBlockHash;
    block.previousBlockHash = ptr->currentBlockHash; // Get the current hash from the previous block
    block.timestamp = newTimestamp;

    // Set the transaction-specific data
    block.transactionId = transactionId;
    block.transactionType = transactionType;
    block.transactionAmount = transactionAmount;
    block.sender = sender;
    block.receiver = receiver;
    block.currency = currency;
    block.transactionStatus = transactionStatus;

    // Return the created block
    return block;
}

//Main function allows users to display the dataset, view the blockchains, or quit the program based on their input
int main() {

    // Define a valid user
    User validUser;
    validUser.username = "username";
    validUser.password = "password";
    bool isAuthenticated = false;
    while (!isAuthenticated){
        // Get input username and password from the user
        string inputUsername, inputPassword;
        cout << "=== User Authentication ===\n";
        cout << "Enter username: ";
        cin >> inputUsername;
        cout << "Enter password: ";
        cin >> inputPassword;
        cout << endl;

        // Perform user authentication
        if (authenticateUser(inputUsername, inputPassword, validUser)) {
            cout << "Authentication successful.Welcome, " << inputUsername << "!\n" <<endl;
            break;
        } else {
            cout << "Authentication failed. Invalid username or password.\n" << endl;
        }
    }

    // Declare variables for each blockchain stage
    SupplierBlockchain supplier;
    PressBlockchain press;
    WeldingBlockchain welding;
    PaintingBlockchain painting;
    AssemblyBlockchain assembly;
    ShippingBlockchain shipping;
    TransactionBlockchain transaction;

    // Loop through the dataset and generate corresponding blockchain blocks
    vector<string> data;
    for (int i = 0; i < 7; i++) {
        data = dataset[i];
        if (i == 0) {
            supplier = generateSupplierBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], data[6]);
        } else if (i == 1) {
            press = generatePressBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], &supplier);
        } else if (i == 2) {
            welding = generateWeldingBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], &press);
        } else if (i == 3) {
            painting = generatePaintingBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], &welding);
        } else if (i == 4) {
            assembly = generateAssemblyBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], &painting);
        } else if (i == 5) {
            shipping = generateShippingBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], &assembly);
        } else if (i == 6) {
            transaction = generateTransactionBlockChain(data[0], data[1], data[2], data[3], data[4], data[5], data[6], &shipping);
        }
    }

    // Menu loop for interacting with the blockchains
    int input;
    bool isLoop = true;
    while (isLoop) {

        // Display menu options
        cout << "--------------- Menu --------------" << endl;
        cout << "|   1. Display the dataset        |" << endl;
        cout << "|   2. Display the blockchains    |" << endl;
        cout << "|   3. Quit                       |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter the number: ";
        cin >> input;

        // Perform action based on user input
        switch (input) {
            case 1:
                printDataset(dataset);
                break;
            case 2:
                printSupplierBlockchain(supplier);
                printPressBlockchain(press);
                printWeldingBlockchain(welding);
                printPaintingBlockchain(painting);
                printAssemblyBlockchain(assembly);
                printShippingBlockchain(shipping);
                printTransactionBlockchain(transaction);
                break;
            case 3:
                isLoop = false;
                break;
            default:
                cout << "Please enter the correct number!" << endl;
        }
    }

    return 0;
}
