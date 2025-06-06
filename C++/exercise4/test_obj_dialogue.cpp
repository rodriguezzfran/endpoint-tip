#include "mock_dialogues.h"
#include "obj_dialogue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <iostream>

using ::testing::Exactly;
using ::testing::StrictMock;
using ::testing::Ref;


TEST(PersonTwoTest, TestPersonTwoHello) {
    // Capturar std::cout
    testing::internal::CaptureStdout();

    StrictMock<MockDialogueOne> mockPersonOne;
    std::unique_ptr<DialogueTwo> p2 = std::make_unique<personTwo>();

    EXPECT_CALL(mockPersonOne, howAreYou(Ref(*p2))).Times(1);

    p2->hello(mockPersonOne);
    
    // Obtener la salida
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar que se imprimió el mensaje esperado
    EXPECT_NE(output.find("PersonTwo: Hello friend"), std::string::npos);
}