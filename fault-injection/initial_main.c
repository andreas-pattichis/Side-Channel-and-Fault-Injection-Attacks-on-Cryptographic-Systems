#include "common.h"
#include "md5.h"

#define readPassword flash_load_img
#define getRealPasswordHash otp_get_img_hash

// FiSim bootloader simulator "magical" function; the name is important - please do not touch
void __attribute__ ((noinline)) flash_load_img(void* base_addr, size_t* size_ptr) {
	*size_ptr = 16;
	
	// The engine will "magically" write some data to this location based on the hardware model
};

// FiSim function to indicate successful glitch
void __attribute__ ((noinline)) authentication_successful(void) {
	// Indicate we successfully bypassed the signature verification
	__SET_SIM_SUCCESS();
}

void bl1_entry() {
	//unsigned char real_password[16]="Test Payload!!!!";
	
	MD5_CTX ctx;  //an object of MD5 class (to compute hash of the password)
	unsigned char provided_password_hash[16];
	unsigned char real_password_hash[16]; 
	bool is_sec_boot_en = false;
	
	unsigned char* provided_password = GUESSED_PASSWORD_MEMORY;
	size_t provided_size;
		
	serial_puts("Start Password Checking...\n");
	otp_init();
	
	otp_is_sec_boot_enabled(&is_sec_boot_en);
	
	if (!is_sec_boot_en) {
		goto authenticated;
	}
		
	getRealPasswordHash(real_password_hash); //hash of real password stored
	readPassword(provided_password, &provided_size);
	
	// computation of hash of the provided password
	MD5_Init(&ctx);
	MD5_Update(&ctx, provided_password, provided_size);
	MD5_Final(provided_password_hash, &ctx);
	
	int mismatch = 0;
	
	// Comparison code
	for (int i = 0; i < 16; i++) {  // Iterate through all 16 bytes of the MD5 hash
		//  If byte in provided_password_hash does't match the corresponding byte in real_password_hash
		if (provided_password_hash[i] != real_password_hash[i]) {
			mismatch = 1;  // Set missmatch to 1, indicating a failure in the authentication
			break;  // Break when a missmatch is found for faster performance
		}
	}

	if(mismatch) {
		serial_puts("Auth failed!\n");
		__SET_SIM_FAILED();
	}
	
authenticated:
	serial_puts("Authenticated!\n");
	authentication_successful();
}