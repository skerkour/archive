pub fn normalize(datum: f64, min: f64, max: f64) -> f64 {
    return (datum - min) / (max - min);
}

pub fn hypothesis(x: f64, t0: f64, t1: f64) -> f64 {
    return t0 + (t1 * x);
}
