// basic library
#include "seal/seal.h"
#include <iostream>

// additional libraries
#include "sealHeader.h"
#include <vector>
#include <string>
#include <time.h>

using namespace std;
using namespace seal;

int main()
{

    clock_t start, end;
    start = clock();

    // input
    vector<double> input{3};

    // operation: encrypt and decrypt
    cout << "encrypt and decrypt x = 3" << endl;

    // parameter set to ckks
    EncryptionParameters parms(scheme_type::ckks);

    // X^N + 1 <--- N=8192
    // q <---- coeff_modulus_degree
    size_t poly_modulus_degree = 8192; // 2^13
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, {60, 40, 40, 60})); // 20

    // scaling factor
    double scale = pow(2.0, 40);

    SEALContext context(parms);

    KeyGenerator keygen(context);
    // secret key
    auto secret_key = keygen.secret_key();
    // public key
    PublicKey public_key;
    keygen.create_public_key(public_key);
    // other keys
    RelinKeys relin_keys;
    keygen.create_relin_keys(relin_keys);
    GaloisKeys gal_keys;
    keygen.create_galois_keys(gal_keys);
    // encryptor, evaluator, decryptor for Enc, Evaluation, Dec
    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secret_key);

    // making slots for encoding
    CKKSEncoder encoder(context);
    size_t slot_count = encoder.slot_count();
    cout << "Number of slots: " << slot_count << endl;

    // encoding
    Plaintext x0_plain;
    encoder.encode(input.at(0), scale, x0_plain);

    // encrypt x0_plain (or 3) to x0_encrypted
    Ciphertext x0_encrypted;
    encryptor.encrypt(x0_plain, x0_encrypted);

    // decrypt
    Plaintext plain_result;
    decryptor.decrypt(x0_encrypted, plain_result);

    // decode
    vector<double> result{};
    encoder.decode(plain_result, result);

    end = clock();

    print_vector(result, 3, 7); // 7 is precision of the result (number of decimals)

    printf("time : %f\n", double((end - start) / CLOCKS_PER_SEC));

    return 0;
}
