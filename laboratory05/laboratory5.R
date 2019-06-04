setwd("/home/jakub/CLionProjects/mownit/laboratory5")
library("ggplot2")

results = read.csv("resultlab3.csv")

show(results)

avg_results = aggregate(cbind(NAIVE, BETTER, GSL) ~ SIZE, data = results, FUN = mean)

show(avg_results)

avg_results$NAIVE_SD = aggregate(NAIVE ~ SIZE, data = results, FUN = sd)$NAIVE
avg_results$BETTER_SD = aggregate(BETTER ~ SIZE, data = results, FUN = sd)$BETTER
avg_results$GSL_SD = aggregate(GSL ~ SIZE, data = results, FUN = sd)$GSL

fitNaive = lm(NAIVE ~ poly(as.vector(avg_results[["SIZE"]]), 3, raw = TRUE), data = avg_results)
dataNaive = data.frame(x = avg_results[["SIZE"]])
dataNaive$y = predict(fitNaive, dataNaive)

fitBetter =  lm(BETTER ~ poly(as.vector(avg_results[["SIZE"]]), 3, raw = TRUE), data = avg_results)
dataBetter = data.frame(x = avg_results[["SIZE"]])
dataBetter$y = predict(fitBetter, dataBetter)

fitGsl =  lm(GSL ~ poly(as.vector(avg_results[["SIZE"]]), 3, raw = TRUE), data = avg_results)
dataGsl = data.frame(x = avg_results[["SIZE"]])
dataGsl$y = predict(fitGsl, dataGsl)

ggplot() +
  geom_point(data = avg_results, aes(SIZE, NAIVE)) +
  geom_point(data = avg_results, aes(SIZE, BETTER)) +
  geom_point(data = avg_results, aes(SIZE, GSL)) +
  geom_errorbar(
    data = avg_results,
    aes(SIZE, NAIVE, ymin = NAIVE - NAIVE_SD, ymax = NAIVE + NAIVE_SD),
    width = 0.5,
    colour = 'red'
    ) +
  geom_errorbar(
    data = avg_results,
    aes(SIZE, BETTER, ymin = BETTER - BETTER_SD, ymax = BETTER + BETTER_SD),
    width = 0.5,
    colour = 'blue'
  ) +
  geom_errorbar(
    data = avg_results,
    aes(SIZE, GSL, ymin = GSL - GSL_SD, ymax = GSL + GSL_SD),
    width = 0.5,
    colour = 'green'
  ) +
  geom_line(data = dataNaive, aes(x, y)) +
  geom_line(data = dataBetter, aes(x, y)) +
  geom_line(data = dataGsl, aes(x, y))
  
  
  