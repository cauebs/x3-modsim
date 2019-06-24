Esta avaliação consiste em: (i) desenvolver uma classe que realize o teste de hipótese paramétrico para uma população; (ii) desenvolver testes unitários para cada método implementado; (iii) documentar o desenvolvimento e os testes realizados.

A implementação do software deve ser feita em C++ STD11 e utilizar as boas práticas de engenharia de software orientado a objetos e padrões de projeto orientados a objeto. A entrega do código-fonte deve ser feita pelo VPL do Moodle. A avaliação considerará quatro quatro aspectos principais: Implementação correta (executa adequadamente e apresenta os resultados corretos sem travamentos ou comportamentos inesperados); Complexidade dos algoritmos utilizados (eficiência do código); Documentação, testes e integração com o sistema de simulação; Apresentação e defesa pelo autor ou membros da equipe (todos os membros).

Para (i), considere que o cálculo das probabilidades deves er feito usando integração numérica por Gauss. Deve haver um método para cada tipo de teste de hipóteses, que retornam o p-value do teste (probabilidade cometer um erro ao rejeitar H0), *da forma mais eficiente possível*. O enum abaixo indica a comparação a ser feita no H1 e, consequentemente, se o teste é unicaudal ou bicaudal.

enum H1Comparition {
DIFFERENT = 1,
LESS_THAN = 2,
GREATER_THAN = 3
};

Os métodos que devem ser implementados são:

double testAverage(double sampleAvg, double sampleStdDev, unsigned long sampleNumElements, double confidencelevel, double avg, H1Comparition comp);
double testProportion(double sampleProp, unsigned long sampleNumElements, double confidencelevel, double prop, H1Comparition comp);
double testVariance(double sampleVar, unsigned long sampleNumElements, double confidencelevel, double var, H1Comparition comp);

Se houver dúvidas sobre o que algum desses métodos deve realizar, contacte o professor o mais rápido possível, via Moodle ou em sala-de-aula. É imprescindível evitar o recálculo desnecessário e garantir precisão numérica, pois a eficiência do código e a precisão do valor de retorno terão peso considerável sobre a nota final.

Para (ii), deve haver um método de teste para cada método implementado (testes unitários), garantindo seu funcionamento. Um programa principal pode invocar cada teste, para facilitar a avaliação. É imprescindível que o valor correto gerado por cada método tenha sido previamente calculado "à mão" para conferência.

Para (iii), explicar s aspectos mais importantes do desenvolvimento. Como a entrega será pelo VPL do Moodle, sua documentação deve ser um arquivo texto simples.

A nota final de cada integrante fica condicionada à demonstração presencial e individual de conhecimento sobre o desenvolvimento feito, de modo que é indispensável a participação de cada integrante da equipe durante a "apresentação e defesa" do X3.
