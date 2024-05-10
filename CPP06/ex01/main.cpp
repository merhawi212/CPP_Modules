#include "Serializer.hpp"

int main(){
	Data *data = new Data;
	data->id = 1;
	data->name = "John";

	// Serialize the orginal object
	uintptr_t  orginal = Serializer::serialize(data);
	// Deserialize the serialized pointer
	Data *deserialized = Serializer::deserialize(orginal);

	PRINT_STATEMENT("orginal: \t id: " << data->id << " name: " << data->name );
	PRINT_STATEMENT("deserialized: \t id: " << deserialized->id << " name: " << deserialized->name);
	
	// Check if the deserialized pointer is equal to the original pointer
    if (deserialized == data) {
        PRINT_STATEMENT("Deserializer successful. Pointers match.");
    } else {
       PRINT_STATEMENT("Deserializer failed. Pointers do not match.");
    }

    // Clean up memory
    delete data;

}
