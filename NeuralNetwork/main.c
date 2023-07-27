//
//  main.c
//  NeuralNetwork
//
//  Created by Ben Fute on 7/26/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1

// Activation function: sigmoid
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}


// Forward pass through the neural network
// The forward function first calculates the output of the hidden layer neurons using the `hidden` array, and then it calculates the final output of the neural network using the `output` array
// The `sigmoid` function is used as the activation function to introduce non-linearity
// The final output is returned, which represents the predicted output of the nueral network for the given input data
double forward(double inputs[INPUT_SIZE], double weights_ih[INPUT_SIZE][HIDDEN_SIZE], double weights_ho[HIDDEN_SIZE][OUTPUT_SIZE], double bias_h[HIDDEN_SIZE], double bias_o[OUTPUT_SIZE])
{
    double hidden[HIDDEN_SIZE];
    double output[OUTPUT_SIZE];
    
    // Calculate hidden layout output
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden[i] += inputs[j] * weights_ih[j][i];
        }
        hidden[i] += bias_h[i];
        hidden[i] = sigmoid(hidden[i]);
    }
    
    // Calculate the final output
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output[i] += hidden[j] * weights_ho[j][i];
        }
        output[i] += bias_o[i];
        output[i] = sigmoid(output[i]);
    }
    
    return output[0]; //Assuming only one output neuron
}


int main() {
    double inputs[INPUT_SIZE] = {0.5, 0.7};
    
    // Weights and biases
    double weights_ih[INPUT_SIZE][HIDDEN_SIZE] = {
        {0.1, 0.4, 0.8},
        {0.3, 0.7, 0.2}
    };
    double weights_ho[HIDDEN_SIZE][OUTPUT_SIZE] = {
        {0.5},
        {0.9},
        {0.6}
    };
    double bias_h[HIDDEN_SIZE] = {0.1, 0.3, 0.5};
    double bias_o[OUTPUT_SIZE] = {0.2};
    
    // Forward pass
    double output = forward(inputs, weights_ih, weights_ho, bias_h, bias_o);
    
    printf("Output: %lf\n", output);
    
    return 0;
}
