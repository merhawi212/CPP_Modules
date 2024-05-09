#include "Serialization.hpp"

int main(){
	Data *data = new Data;
	data->id = 1;
	data->name = "John";

	// Serialize the orginal object
	uintptr_t  orginal = Serialization::serialize(data);
	// Deserialize the serialized pointer
	Data *deserialized = Serialization::deserialize(orginal);

	PRINT_STATEMENT("orginal: \t id: " << data->id << " name: " << data->name );
	PRINT_STATEMENT("deserialized: \t id: " << deserialized->id << " name: " << deserialized->name);
	
	// Check if the deserialized pointer is equal to the original pointer
    if (deserialized == data) {
        std::cout << "Deserialization successful. Pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    }

    // Clean up memory
    delete data;

}
